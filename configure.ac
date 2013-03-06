AC_INIT(halttimer, 0.1, [fabian@hirschm.net], [halttimer])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_PROG_CC
AM_PROG_CC_C_O
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile man/Makefile])
AM_MISSING_PROG([HELP2MAN], [help2man])

AC_MSG_CHECKING(if LIRC support is enabled)
lirc=yes
AC_ARG_ENABLE([lirc],
  AC_HELP_STRING([--disable-lirc], [disable lirc support]),
[
if test "x${enableval}" = "xyes" -a "x$GCC" = "xyes"; then
  AC_MSG_RESULT(yes)
  lirc=yes
else
  AC_MSG_RESULT(no)
  lirc=no
fi], AC_MSG_RESULT(no))


AC_ARG_WITH(lirc-prefix,
[  --with-lirc-prefix=PATH Prefix where LIRC is installed],
[
for dir in `echo "$withval" | tr : ' '`; do
  if test -d $dir/lib; then CXXFLAGS="$CXXFLAGS -L$dir/lib"; fi
  if test -d $dir/include; then CXXFLAGS="$CXXFLAGS -I$dir/include"; fi
  done
])

HAVE_LIRC=no
if test "x${lirc}" != "xno" ; then
  AC_CHECK_HEADER(lirc/lirc_client.h,
    [AC_CHECK_LIB(lirc_client,lirc_init,[HAVE_LIRC=yes;LIBS=-llirc_client $LIBS;AC_DEFINE([HAVE_LIRC],[],[Define to 1 if LIRC must be used])],,)],)
fi
AM_CONDITIONAL(HAVE_LIRC, [test "x$HAVE_LIRC" = xyes])

# Checking for xosd-config.
AC_PATH_PROG([xosdconfigpath], [xosd-config], [no])
if test "$xosdconfigpath" = "no"; then
    AC_MSG_ERROR([xosd-config binary is required])
fi

XOSD_CFLAGS=`$xosdconfigpath --cflags`
if test -z "$XOSD_CFLAGS"; then
    AC_MSG_RESULT([not found.])
    exit
fi

XOSD_LDFLAGS=`$xosdconfigpath --libs`
if test -z "$XOSD_LDFLAGS"; then
    AC_MSG_RESULT([not found.])
    exit
fi

AC_SUBST(XOSD_CFLAGS)
AC_SUBST(XOSD_LDFLAGS)


AC_OUTPUT
