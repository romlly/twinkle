/*
    Copyright (C) 2005-2009  Michel de Boer <michel@twinklephone.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "hdr_www_authenticate.h"
#include "definitions.h"

t_hdr_www_authenticate::t_hdr_www_authenticate() : t_header("WWW-Authenticate") {}

void t_hdr_www_authenticate::set_challenge(const t_challenge &c) {
	populated = true;
	challenge = c;
}

string t_hdr_www_authenticate::encode_value(void) const {
	if (!populated) return "";

	return challenge.encode();
}
