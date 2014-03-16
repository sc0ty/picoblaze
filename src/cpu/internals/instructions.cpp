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

	Instruction execution module
*/

#include <cstring>

#include "instructions.h"
#include "instruction.h"
#include "../cpu.h"

Instructions::Instructions() : instr(NULL), size(0), pc(0)
{
}

Instructions::~Instructions()
{
    this->free();
}

void Instructions::allocate(unsigned int size)
{
    this->free();
    this->instr = new Instruction[size];
    this->size = size;
    this->pc = 0;
}

void Instructions::free()
{
    delete [] this->instr;
    this->instr = NULL;
    this->size = 0;
}

unsigned int Instructions::getPC()
{
    return this->pc;
}

void Instructions::setPC(unsigned int pc)
{
    if (pc < this->size)
        this->pc = pc;
}

Instruction *Instructions::getInstruction(unsigned int addr)
{
    if (addr < this->size)
        return &this->instr[addr];

    return NULL;
}

unsigned int Instructions::getSize()
{
    return this->size;
}

void Instructions::load(const uint32_t *buf, unsigned int size)
{
    unsigned int len = size;
    unsigned int i;

    if (size > this->size)
        len = this->size;

    for (i=0; i<len; ++i)
        this->instr[i].setCode(buf[i]);

    for (; i<this->size; ++i)
        this->instr[i].setCode(0);
}

void Instructions::clear()
{
    memset(this->instr, 0, this->size*sizeof(uint32_t));
}

void Instructions::execute(Cpu &cpu)
{
    this->instr[ this->pc ].execute(cpu);

    this->pc++;
    if (this->pc >= this->size)
        this->pc %= this->size;
}

void Instructions::interrupt(Cpu &cpu)
{
    unsigned int pc2;

    if (this->pc > 0)
        pc2 = this->pc - 1;
    else
        pc2 = Cpu::INSTRUCTIONS_NO;

    cpu.stack.push(pc2);
    this->pc = 0x3ff;

    cpu.flags.ie = false;
    cpu.flags.preserve();
}

void Instructions::reset()
{
    this->pc = 0;
}
