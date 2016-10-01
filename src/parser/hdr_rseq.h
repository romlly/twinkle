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

// RSeq header
// RFC 3262

#ifndef _HDR_RSEQ
#define _HDR_RSEQ

#include <string>
#include "header.h"
#include "definitions.h"

using namespace std;

class t_hdr_rseq : public t_header {
public:
	unsigned long 		resp_nr;

	t_hdr_rseq();
	void set_resp_nr(unsigned long l);

	string encode_value(void) const;

	bool operator==(const t_hdr_rseq &h) const;
};

#endif
