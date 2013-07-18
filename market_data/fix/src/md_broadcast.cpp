//
// System K - A framework for building trading applications and analysis
// Copyright (C) 2013 Timir Karia <tkaria@capitalkpartners.com>
//
// This file is part of System K.
//
// System K is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// System K is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with System K.  If not, see <http://www.gnu.org/licenses/>.
//

#include "md_broadcast.h"
#include "utils/types.h"
#include "proto/spot_fx_md_1.pb.h"
#ifdef LOG 
#include "utils/logging.h"
#endif // LOG

#include <iostream>

#include <zmq.hpp>

namespace capk {

/**
 * Create the ZMQ context and set socket options
 * for the pub socket on which we'll broadcast market data
 * @return 0 on success
 */
int InitializeZMQPublisher(void** context, void** socket) {
  int zero = 0;
  /** Initialize the global context */
  *context = zmq_init(1);
  assert(*context);

  /** Setup the socket for publishing prices */
  *socket = zmq_socket(*context, ZMQ_PUB);
  zmq_setsockopt(*socket, ZMQ_LINGER, &zero, sizeof(zero));
  assert(*socket);

  if (*context == NULL || *socket == NULL) {
    return (-1);
  }
  return 0;
}

/**
 * Given socket and data to fill the instrument_bbo protocol buffer
 * create the protobuf structure and serialize it onto the socket
 */
void BroadcastBBOBook(void* bcast_socket,
                        const char* symbol,
                        const double best_bid,
                        const double best_ask,
                        const double bbsize,
                        const double basize,
                        const capk::venue_id_t venue_id) {
  zmq_msg_t msg;
  char msgbuf[MAX_MSG_SIZE];
  capkproto::instrument_bbo bbo;

  bbo.set_symbol(symbol);
  bbo.set_bid_price(best_bid);
  bbo.set_ask_price(best_ask);
  bbo.set_bid_size(bbsize);
  bbo.set_ask_size(basize);
  bbo.set_bid_venue_id(venue_id);
  bbo.set_ask_venue_id(venue_id);

  size_t msgsize = bbo.ByteSize();
  assert(msgsize < sizeof(msgbuf));
  if (msgsize > sizeof(msgbuf)) {
#ifdef LOG
    pan::log_CRITICAL("Buffer too small for protobuf serializaion");
#endif
    std::cerr << "CRITIAL: Buffer too small for protobuf serialization"
              << std::endl;
  }
  bbo.SerializeToArray(msgbuf, msgsize);

  zmq_msg_init_size(&msg, msgsize);
  memcpy(zmq_msg_data(&msg), msgbuf, msgsize);
#ifdef LOG
    pan::log_DEBUG("Sending ", pan::integer(msgsize), " bytes\n");
    pan::log_DEBUG("Protobuf string:\n", bbo.DebugString().c_str(), "\n");
#endif
  zmq_send(bcast_socket, &msg, 0);
}


} // namespace capk
