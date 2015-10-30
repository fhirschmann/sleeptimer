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

man_MANS = sleeptimer.1
EXTRA_DIST = $(man_MANS)
MAINTAINERCLEANFILES = $(man_MANS)

common_mandeps = $(top_srcdir)/configure.ac

sleeptimer.1: $(top_srcdir)/src/sleeptimer.c $(common_mandeps)
	$(HELP2MAN) \
		--no-info \
		--include=inc.h2m \
		$(top_srcdir)/src/sleeptimer -o $@

print: sleeptimer.1
	nroff -man sleeptimer.1
