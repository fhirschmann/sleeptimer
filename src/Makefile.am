# Copyright (c) 2013-2015 Fabian Hirschmann <fabian@hirschmann.email>
#
# This file is part of sleeptimer.
#
# Sleeptimer is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Sleeptimer is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Sleeptimer.  If not, see <http://www.gnu.org/licenses/>.

AM_CPPFLAGS = -DLOCALEDIR=\"$(localedir)\"

bin_PROGRAMS = sleeptimer

sleeptimer_SOURCES = sleeptimer.c gettext.h
sleeptimer_CFLAGS = -Wall -Werror
sleeptimer_LDADD = @XOSD_LDFLAGS@
if HAVE_LIRC
	sleeptimer_LDADD += -llirc_client
endif

LDADD = $(LIBINTL)
