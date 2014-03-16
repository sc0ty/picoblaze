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

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <stdint.h>

class Instruction;
class Cpu;

class Instructions
{
    friend class Instruction;

public:
    Instructions();
    ~Instructions();

    void allocate(unsigned int size);
    void free();

    unsigned int getPC();
    void setPC(unsigned int pc);

    unsigned int getSize();
    Instruction *getInstruction(unsigned int addr);

    void load(const uint32_t *buf, unsigned int size);
    void clear();

    void execute(Cpu &cpu);
    void interrupt(Cpu &cpu);
    void reset();

private:
    Instruction *instr;
    unsigned int size;
    unsigned int pc;    // program counter
};

#endif // INSTRUCTIONS_H
