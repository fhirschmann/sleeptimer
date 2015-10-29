# Copyright (c) 2013 Fabian Hirschmann <fabian@hirschmann.email>
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

SUBDIRS = po src man

README.md: man/sleeptimer.1
	sed -i '/## Manual/q' README.md
	nroff -man man/sleeptimer.1 | col -b | awk '{ print "    " $$0 }' >> README.md

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = config.rpath README.md
dist_bin_SCRIPTS = scripts/sleeptimer-action
