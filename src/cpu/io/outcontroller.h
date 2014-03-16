/*
	PicoBlaze Simulator
	Copyright (c) 2014 Mike Szymaniak <sc0typl@gmail.com>

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

	Output port controller
*/

#ifndef OUTCONTROLLER_H
#define OUTCONTROLLER_H

#include <list>
#include <string>

#include "output.h"

using namespace std;

class OutController
{
    friend class Instruction;

public:
    OutController();

    uint8_t get();
    void set(uint8_t value);

    Output *attach(Output *out);
    void detach(Output *out);
    void detachAll();

    string getName();

private:
    uint8_t value;
    list<Output*> outs;
};

#endif // OUTCONTROLLER_H
