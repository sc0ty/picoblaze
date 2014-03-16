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

#include "outcontroller.h"

OutController::OutController() : value(0)
{
}

uint8_t OutController::get()
{
    return this->value;
}

void OutController::set(uint8_t value)
{
    this->value = value;

    list<Output*>::iterator it;

    for (it=outs.begin(); it!=outs.end(); ++it)
        (*it)->set(value);
}

Output *OutController::attach(Output *out)
{
    this->outs.push_back(out);
    out->set( this->value );
    return out;
}

void OutController::detach(Output *out)
{
    this->outs.remove(out);
}

void OutController::detachAll()
{
    this->outs.clear();
}

string OutController::getName()
{
    string name;
    list<Output*>::iterator it;

    for (it=outs.begin(); it!=outs.end(); ++it)
    {
        if (!name.empty())
            name += ", ";

        name += (*it)->getName();
    }

    return name;
}
