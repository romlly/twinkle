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

#include "definitions.h"
#include "hdr_rack.h"
#include "util.h"

t_hdr_rack::t_hdr_rack() : t_header("RAck") {
	cseq_nr = 0;
	resp_nr = 0;
	method = INVITE;
}

void t_hdr_rack::set_cseq_nr(unsigned long l) {
	populated = true;
	cseq_nr = l;
}

void t_hdr_rack::set_resp_nr(unsigned long l) {
	populated = true;
	resp_nr = l;
}

void t_hdr_rack::set_method(t_method m, const string &unknown) {
	populated = true;
	method = m;
	unknown_method = unknown;
}

void t_hdr_rack::set_method(const string &s) {
	populated = true;
	method = str2method(s);
	if (method == METHOD_UNKNOWN) {
		unknown_method = s;
	}
}

string t_hdr_rack::encode_value(void) const {
	string s;

	if (!populated) return s;

	s = ulong2str(resp_nr) + ' ';
	s += ulong2str(cseq_nr);
	s += ' ';
	s += method2str(method, unknown_method);

	return s;
}
