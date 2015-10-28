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

SUBDIRS = po src man

README.md: man/halttimer.1
	sed -i '/## Manual/q' README.md
	nroff -man man/halttimer.1 | col -b | awk '{ print "    " $$0 }' >> README.md

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = config.rpath m4/ChangeLog README.md config.rpath
