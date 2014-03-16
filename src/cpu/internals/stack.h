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

#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    Stack();
    ~Stack();

    void allocate(unsigned int size);
    void free();
    void clear();

    void push(unsigned int value);
    unsigned int pop();
    void reset();

    unsigned int getSP();
    void setSP(unsigned int sp);

    unsigned int getValue(unsigned int address);
    void setValue(unsigned int address, unsigned int value);

private:
    unsigned int *buf;
    unsigned int size;
    unsigned int sp;
};

#endif // STACK_H
