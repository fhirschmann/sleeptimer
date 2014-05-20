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

man_MANS = halttimer.1
EXTRA_DIST = $(man_MANS)
MAINTAINERCLEANFILES = $(man_MANS)

common_mandeps = $(top_srcdir)/configure.ac

halttimer.1: $(top_srcdir)/src/halttimer.c $(common_mandeps)
	$(HELP2MAN) \
		--no-info \
		--include=inc.h2m \
		$(top_srcdir)/src/halttimer -o $@

print: halttimer.1
	nroff -man halttimer.1
