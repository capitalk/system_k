AC_INIT([system_k], [0.0.1])
AC_CONFIG_AUX_DIR([.])
AM_INIT_AUTOMAKE, 
AC_PROG_LIBTOOL
AC_PROG_CXX
AC_PROG_CC
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_FILES([Makefile])

AC_ARG_WITH([protobuf-libdir],
    [AS_HELP_STRING([--with-protobuf-libdir=LIB_DIR],
        [location of the protocol buffers libraries, defaults to /usr/lib])],
    [PROTOBUF_LIBDIR="$withval"],
    [PROTOBUF_LIBDIR='/usr/lib'])
AC_SUBST([PROTOBUF_LIBDIR])

LDFLAGS="$LDFLAGS -L$PROTOBUF_LIBDIR"

AC_CHECK_LIB([protobuf], [main], [], [AC_MSG_ERROR([cannot find protobuf library])])

AC_ARG_WITH([protoc],
    [AS_HELP_STRING([--with-protoc=PATH],
        [location of the protoc protocol buffer compiler binary, defaults to protoc])],
    [PROTOC="$withval"],
    [PROTOC='protoc'])
AC_SUBST([PROTOC])

AC_CONFIG_SUBDIRS([common/proto])
AC_CONFIG_SUBDIRS([order_book])
AC_CONFIG_SUBDIRS([market_data/fix])
AC_OUTPUT
