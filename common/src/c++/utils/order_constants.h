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

#ifndef __ORDER_CONSTANTS_H__
#define __ORDER_CONSTANTS_H__

//#include "msg_cache.h"
#include "utils/types.h"
#include "utils/constants.h"
// These definitions are based on fix 4.2 dictionary from fixprotocol.org
// but should be pretty universal since we're using a relatively small subset
// of the FIX protocol

namespace capk {

#define ACCOUNT_LEN 16
#define EXEC_REF_ID_LEN 128
#define EXEC_ID_LEN 128


enum internal_order_state {
  INT_STATE_PENDING_CANCEL = 12,
  INT_STATE_PENDING_REPLACE = 11,
  INT_STATE_DONE_FOR_DAY = 10,
  INT_STATE_CALCULATED = 9,
  INT_STATE_FILLED = 8,
  INT_STATE_STOPPED = 7,
  INT_STATE_SUSPENDED = 6,
  INT_STATE_CANCELED = 5,
  INT_STATE_EXPIRED = 5,
  INT_STATE_PARTIALLY_FILLED = 4,
  INT_STATE_REPLACED = 3,
  INT_STATE_NEW = 2,
  INT_STATE_REJECTED = 2,
  INT_STATE_PENDING_NEW = 2,
  INT_STATE_ACCEPTED_FOR_BIDDING = 1,
  INT_STATE_UNINIT = 0
};
typedef enum internal_order_state OrderState_t;

// Exec transaction type - FIX tag 20
enum exec_trans_type {
  NO_EXEC_TRAN = -1,
  EXEC_TRAN_NEW = '0',
  EXEC_TRAN_CANCEL = '1',
  EXEC_TRAN_CORRECT = '2',
  EXEC_TRAN_STATUS = '3'
};
typedef enum exec_trans_type ExecTransType_t;

// Order status - FIX tag 39
enum ord_status {
  NO_ORD_STATUS = -1,
  ORD_STATUS_NEW = '0',
  ORD_STATUS_PARTIAL_FILL = '1',
  ORD_STATUS_FILL = '2',
  ORD_STATUS_DONE_FOR_DAY = '3',
  ORD_STATUS_CANCELLED = '4',
  ORD_STATUS_REPLACE = '5',
  ORD_STATUS_PENDING_CANCEL = '6',
  ORD_STATUS_STOPPED = '7',
  ORD_STATUS_REJECTED = '8',
  ORD_STATUS_SUSPENDED = '9',
  ORD_STATUS_PENDING_NEW = 'A',
  ORD_STATUS_CALCULATED = 'B',
  ORD_STATUS_EXPIRED = 'C',
  ORD_STATUS_RESTATED = 'D',
  ORD_STATUS_PENDING_REPLACE = 'E'
};
typedef enum ord_status OrdStatus_t;

// Exec types - FIX tag 150
enum exec_type {
  NO_EXEC_TYPE = -1,
  EXEC_TYPE_NEW = '0',
  EXEC_TYPE_PARTIAL_FILL = '1',
  EXEC_TYPE_FILL = '2',
  EXEC_TYPE_DONE_FOR_DAY = '3',
  EXEC_TYPE_CANCELLED = '4',
  EXEC_TYPE_REPLACE = '5',
  EXEC_TYPE_PENDING_CANCEL = '6',
  EXEC_TYPE_STOPPED = '7',
  EXEC_TYPE_REJECTED = '8',
  EXEC_TYPE_SUSPENDED = '9',
  EXEC_TYPE_PENDING_NEW = 'A',
  EXEC_TYPE_CALCULATED = 'B',
  EXEC_TYPE_EXPIRED = 'C',
  EXEC_TYPE_RESTATED = 'D',
  EXEC_TYPE_PENDING_REPLACE = 'E'	
};
typedef enum exec_type ExecType_t;


// Order Types - FIX tag 40 
typedef char OrdType_t;
const char ORD_TYPE_MARKET = '1';
const char ORD_TYPE_LIMIT = '2';
const char ORD_TYPE_STOP = '3';
const char ORD_TYPE_STOP_LIMIT = '4';
const char ORD_TYPE_MARKET_ON_CLOSE = '5';
const char ORD_TYPE_WITH_OR_WITHOUT = '6';
const char ORD_TYPE_LIMIT_OR_BETTER = '7';
const char ORD_TYPE_LIMIT_WITH_OR_WITHOUT = '8';
const char ORD_TYPE_ON_BASIS = '9';
const char ORD_TYPE_ON_CLOSE = 'A';
const char ORD_TYPE_LIMIT_ON_CLOSE = 'B';
const char ORD_TYPE_FOREX_MARKET = 'C';
const char ORD_TYPE_PREVIOUSLY_QUOTED = 'D';
const char ORD_TYPE_PREVIOUSLY_INDICATED = 'E';
const char ORD_TYPE_FOREX_LIMIT = 'F';
const char ORD_TYPE_FOREX_SWAP = 'G';
const char ORD_TYPE_FOREX_PREVIOUSLY_QUOTED = 'H';
const char ORD_TYPE_FUNARI = 'I'; // limit day order with executed portion handled as Market On Close e.g. Japan...
const char ORD_TYPE_PEGGED = 'P';

// Exec instruction - FIX tag 18
//typedef char exec_inst_t;
const char EXEC_INST_STAY_ON_OFFERSIDE = '0';
const char EXEC_INST_NOT_HELD = '1';
const char EXEC_INST_WORK = '2';
const char EXEC_INST_GO_ALONG = '3';
const char EXEC_INST_OVER_THE_DAY = '4';
const char EXEC_INST_HELD = '5';
const char EXEC_INST_PARTICIPATE_DONT_INITIATE = '6';
const char EXEC_INST_STRICT_SCALE = '7';
const char EXEC_INST_TRY_TO_SCALE = '8';
const char EXEC_INST_STAY_ON_BIDSIDE = '9';
const char EXEC_INST_NO_CROSS = 'A';
const char EXEC_INST_OK_TO_CROSS = 'B';
const char EXEC_INST_CALL_FIRST = 'C';
const char EXEC_INST_PERCENT_OF_VOLUME = 'D';
const char EXEC_INST_DO_NOT_INCREASE = 'E';
const char EXEC_INST_DNI = 'E';
const char EXEC_INST_DO_NOT_REDUCE = 'F';
const char EXEC_INST_DNR = 'F';
const char EXEC_INST_ALL_OR_NONE = 'G';
const char EXEC_INST_AON = 'G';
const char EXEC_INST_INSTITUTIONS_ONLY = 'I';
const char EXEC_INST_LAST_PEG = 'L';
const char EXEC_INST_MIDPRICE_PEG = 'M'; // midprice of inside quote
const char EXEC_INST_NON_NEGOTIABLE = 'N';
const char EXEC_INST_OPENING_PEG = 'O';
const char EXEC_INST_MARKET_PEG = 'P';
const char EXEC_INST_PRIMARY_PEG = 'R'; // peg to primary market - buy at bid/sell at offer
const char EXEC_INST_SUSPEND = 'S';
const char EXEC_INST_FIXED_PEG = 'T'; // peg to local best bid or offer at time of order
const char EXEC_INST_CUSTOMER_DISPLAY_INSTRUCTION = 'U';
const char EXEC_INST_NETTING = 'V';
const char EXEC_INST_PEG_TO_VWAP = 'W';


// OrdRejReason - order reject reason - FIX tag 103
typedef int OrdRejectReason_t;
const int REJECT_BROKER_OPTION = 0;
const int REJECT_UNKNOWN_SYMBOL = 1;
const int REJECT_EXCHANGE_CLOSED = 2;
const int REJECT_ORDER_EXCEEDS_LIMIT = 3;
const int REJECT_TOO_LATE_TO_ENTER = 4;
const int REJECT_UNKNOWN_ORDER = 5;
const int REJECT_DUPLICATE_ORDER = 6;
const int REJECT_DUPLICATE_VERBAL_ORDER = 7;
const int REJECT_STALE_ORDER = 8;

// Handling instructions - FIX tag 21
typedef char HandlInst_t;
const char HANDL_INST_AUTOMATED_NO_INTERVENTION = '1';
const char HANDL_INST_AUTOMATED_INTERVENTION_OK = '2';
const char HANDL_INST_MANUAL = '3'; // Manual order, best execution

// Time in Force - FIX tag 59
typedef char TimeInForce_t;
const char TIF_DAY = '0';
const char TIF_GTC = '1';
const char TIF_GOOD_TIL_CANCEL = '1';
const char TIF_OPG = '2';
const char TIF_AT_THE_OPENING = '2';
const char TIF_IOC = '3';
const char TIF_IMMEDIATE_OR_CANCEL = '3';
const char TIF_FOK = '4';
const char TIF_FILL_OR_KILL = '4';
const char TIF_GTX = '5';
const char TIF_GOOD_TIL_CROSSING = '5';
const char TIF_GTD = '6';
const char TIF_GOOD_TIL_DATE = '6';

// Security Types - FIX tag 167
#define SEC_TYPE_LEN 5
const char* const SEC_TYPE_FOR= "FOR"; //	Foreign Exchange Contract [ForeignExchangeContract]	
/*
const char* SEC_TYPE_WILDCARD = "?";//	Wildcard entry (used on Security Definition Request message)
const char* SEC_TYPE_BANKERSACCEPTANCE = "BA";
const char* SEC_TYPE_CB = "CB"; //Convertible Bond (Note not part of ISITC spec) [ConvertibleBond]	
const char* SEC_TYPE_CD = "CD"; //Certificate Of Deposit [CertificateOfDeposit]	
const char* SEC_TYPE_CMO = "CMO"; //Collateralize Mortgage Obligation [CollateralizedMortgageObligation]	
const char* SEC_TYPE_CORP= "CORP"; //Corporate Bond [CorporateBond]	
const char* SEC_TYPE_CP= "CP"; //Commercial Paper [CommercialPaper]	
const char* SEC_TYPE_CPP= "CPP"; //Corporate Private Placement [CorporatePrivatePlacement]	
const char* SEC_TYPE_CS= "CS"; //Common Stock [CommonStock]	
const char* SEC_TYPE_FHA= "FHA"; //Federal Housing Authority [FederalHousingAuthority]	
const char* SEC_TYPE_FHL= "FHL"; //Federal Home Loan [FederalHomeLoan]	
const char* SEC_TYPE_FN= "FN"; //Federal National Mortgage Association [FederalNationalMortgageAssociation]	
const char* SEC_TYPE_FUT= "FUT"; //	Future [Future]	
const char* SEC_TYPE_GN= "GN"; //	Government National Mortgage Association [GovernmentNationalMortgageAssociation]	
const char* SEC_TYPE_GOVT= "GOVT"; //	Treasuries + Agency Debenture [TreasuriesAgencyDebenture]	
const char* SEC_TYPE_IET= "IET"; //	Mortgage IOETTE [IOETTEMortgage]	
const char* SEC_TYPE_MF= "MF"; //	Mutual Fund [MutualFund]	
const char* SEC_TYPE_MIO= "MIO"; //	Mortgage Interest Only [MortgageInterestOnly]	
const char* SEC_TYPE_MPO= "MPO"; //	Mortgage Principal Only [MortgagePrincipalOnly]	
const char* SEC_TYPE_MPP= "MPP"; //	Mortgage Private Placement [MortgagePrivatePlacement]	
const char* SEC_TYPE_MPT= "MPT"; //	Miscellaneous Pass-Thru [MiscellaneousPassThrough]	
const char* SEC_TYPE_MUNI= "MUNI"; //	Municipal Bond [MunicipalBond]	
const char* SEC_TYPE_NONE= "NONE"; //	No ISITC Security Type [NoSecurityType]	
const char* SEC_TYPE_OPT= "OPT"; //	Option [Option]	
const char* SEC_TYPE_PS= "PS"; //	Preferred Stock [PreferredStock]	
const char* SEC_TYPE_RP= "RP"; //	Repurchase Agreement [RepurchaseAgreement]	
const char* SEC_TYPE_RVRP= "RVRP"; //	Reverse Repurchase Agreement [ReverseRepurchaseAgreement]	
const char* SEC_TYPE_SL= "SL"; //	Student Loan Marketing Association [StudentLoanMarketingAssociation]	
const char* SEC_TYPE_TD= "TD"; //	Time Deposit [TimeDeposit]	
const char* SEC_TYPE_USTB= "USTB"; //	US Treasury Bill [USTreasuryBillOld]	
const char* SEC_TYPE_WAR= "WAR"; //	Warrant [Warrant]	
const char* SEC_TYPE_ZOO= "ZOO"; //	Cats, Tigers & Lions (a real code: US Treasury Receipts) [CatsTigersAndLions]
*/

// OrdRejReason - order reject reason - FIX tag 103
typedef int ExecRestatementReason_t;
const int RESTATE_CORPORATE_ACTION = 0;
const int RESTATE_RENEWAL = 1;
const int RESTATE_VERBAL = 2;
const int RESTATE_REPRICE = 3;
const int RESTATE_BROKER_OPTION = 4;
const int RESTATE_PARTIAL_DECLINE = 5;



}; // namespace capk
#endif // __ORDER_CONSTANTS_H__

