# Copyright (c) 2013 Fabian Hirschmann <fabian@hirschm.net>
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

AM_CPPFLAGS = -DLOCALEDIR=\"$(localedir)\"

bin_PROGRAMS = halttimer

halttimer_SOURCES = halttimer.c gettext.h
halttimer_LDFLAGS = @XOSD_LDFLAGS@
if HAVE_LIRC
	halttimer_LDFLAGS += -llirc_client
endif

LDADD = $(LIBINTL)
