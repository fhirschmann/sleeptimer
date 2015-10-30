#!/bin/sh -e
#
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

# Work around gettext < 0.18.2 requiring a gettext version
GV=$(gettext --version | head -n1 | awk '{ print $4 }')
sed -r "s/(AM_GNU_GETTEXT_VERSION\(\[).*(\]\))/\1$GV\2/" -i configure.ac

exec autoreconf -i
