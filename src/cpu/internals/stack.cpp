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

	Stack module
*/

#include <cstring>

#include "stack.h"

Stack::Stack() : buf(NULL), size(0), sp(0)
{
}

Stack::~Stack()
{
    this->free();
}

void Stack::allocate(unsigned int size)
{
    this->free();
    this->buf = new unsigned int[size];
    this->size = size;
    this->clear();
}

void Stack::free()
{
    delete [] this->buf;
    this->buf = NULL;
    this->size = 0;
    this->sp = 0;
}

void Stack::clear()
{
    memset(this->buf, 0, this->size*sizeof(unsigned int));
    this->sp = 0;
}

void Stack::push(unsigned int value)
{
    this->buf[ this->sp++ ] = value;

    if (this->sp >= this->size)
        this->sp = 0;
}

unsigned int Stack::pop()
{
    if (this->sp == 0)
        this->sp = this->size;

    this->sp--;
    return this->buf[this->sp];
}

void Stack::reset()
{
    this->sp = 0;
}

unsigned int Stack::getSP()
{
    return this->sp;
}

void Stack::setSP(unsigned int sp)
{
    if (sp < this->size)
        this->sp = sp;
}

unsigned int Stack::getValue(unsigned int address)
{
    if (address < this->size)
        return this->buf[address];

    return 0;
}

void Stack::setValue(unsigned int address, unsigned int value)
{
    if (address < this->size)
        this->buf[address] = value;
}
