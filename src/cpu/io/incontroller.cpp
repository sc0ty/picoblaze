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

#include "incontroller.h"

InController::InController() : value(0), isAttached(false)
{
}

uint8_t InController::get()
{
    return this->value;
}

void InController::set(uint8_t value)
{
    this->value = value;
}

uint8_t *InController::attach(const string name)
{
    if (this->isAttached == false)
    {
        this->isAttached = true;
        this->name = name;
        return &this->value;
    }

    return NULL;
}

void InController::detach(uint8_t *in)
{
    if (in == &this->value)
    {
        this->isAttached = false;
        this->value = 0;
        this->name.clear();
    }
}

string InController::getName()
{
    return this->name;
}
