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

	Processor flags
*/

#include "flags.h"

Flags::Flags()
{
    this->reset();
}

void Flags::reset()
{
    this->cf = false;
    this->zf = false;
    this->ie = false;

    this->preservedCf = false;
    this->preservedZf = false;
}

void Flags::preserve()
{
    this->preservedCf = this->cf;
    this->preservedZf = this->zf;
}

void Flags::restore()
{
    this->cf = this->preservedCf;
    this->zf = this->preservedZf;
}

