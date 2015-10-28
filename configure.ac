# Copyright (c) 2013 Fabian Hirschmann <fabian@hirschmann.email>
#
# This file is part of halttimer.
#
# Halttimer is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Halttimer is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Halttimer.  If not, see <http://www.gnu.org/licenses/>.

# Prelude.
AC_INIT(halttimer, 0.3.2, [fabian@hirschmann.email], [halttimer],
        http://github.com/fhirschmann/halttimer.git)
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AM_GNU_GETTEXT_VERSION([0.18.2])
AM_GNU_GETTEXT([external])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AM_MISSING_PROG([HELP2MAN], [help2man])

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

# Checks for libraries.
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

# Output files.
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile man/Makefile po/Makefile.in])
AC_OUTPUT
