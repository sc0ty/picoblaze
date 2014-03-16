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

	Input port controller
*/

#ifndef INCONTROLLER_H
#define INCONTROLLER_H

#include <stdint.h>
#include <string>

using namespace std;

class InController
{
    friend class Instruction;

public:
    InController();

    uint8_t get();
    void set(uint8_t value);

    uint8_t *attach(const string name);
    void detach(uint8_t *in);

    string getName();

private:
    uint8_t value;
    string name;
    bool isAttached;
};

#endif // INCONTROLLER_H
