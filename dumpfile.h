/*
    This file is part of Kismet

    Kismet is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Kismet is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kismet; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __DUMPFILE_H__
#define __DUMPFILE_H__

#include "config.h"

#include <stdio.h>
#include <string>

#include "globalregistry.h"
#include "configfile.h"
#include "messagebus.h"
#include "packetchain.h"
#include "filtercore.h"

class Dumpfile {
public:
	Dumpfile();
	Dumpfile(GlobalRegistry *in_globalreg);
	virtual ~Dumpfile() { };

	static void Usage(char *name);

	// Fetch the number of items logged
	int FetchNumDumped() { return dumped_frames; }

	// Fetch the name of the file being dumped to
	string FetchFileName() { return fname; }

	// Cleanly flush the file to disk
	virtual int Flush() = 0;

protected:
	GlobalRegistry *globalreg;
	FilterCore *export_filter;
	string fname;

	int dumped_frames;

	virtual string ProcessConfigOpt(string in_type);
};

#endif

