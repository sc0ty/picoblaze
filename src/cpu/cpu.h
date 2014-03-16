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

	Processor simulation class
*/

#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#include "internals/instructions.h"
#include "internals/stack.h"
#include "internals/flags.h"
#include "io/outcontroller.h"
#include "io/incontroller.h"

class Cpu
{
    friend class Instruction;
    friend class Instructions;

public:
    static const unsigned int RAM_SIZE = 64;
    static const unsigned int REGS_NO = 16;
    static const unsigned int IO_PORTS_NO = 256;
    static const unsigned int STACK_SIZE = 31;
    static const unsigned int INSTRUCTIONS_NO = 1024;

public:
    Cpu();
    ~Cpu();

    void loadHex(const char *fileName);

    void execute();
    void reset();
    void generateInt();

    uint8_t getRegister(unsigned int no);
    void setRegister(unsigned int no, uint8_t value);
    uint8_t getRam(unsigned int addr);
    void setRam(unsigned int addr, uint8_t value);
    unsigned int getStack(unsigned int addr);
    void setStack(unsigned int addr, unsigned int value);

    unsigned int getPC();           // Program Counter
    void setPC(unsigned int pc);
    unsigned int getSP();           // Stack Pointer
    void setSP(unsigned int sp);

    bool getCF();           // Carry Flag
    void setCF(bool f);
    bool getZF();           // Zero Flag
    void setZF(bool f);
    bool getIE();           // Interrupt Enable
    void setIE(bool f);

    void clearRegisters();
    void clearRam();
    void clearStack();
    void clearFlags();
    void clear();

    uint32_t getInstructionCode(unsigned int addr);
    void setInstructionCode(unsigned int addr, uint32_t code);

    OutController outs[IO_PORTS_NO];
    InController ins[IO_PORTS_NO];

    void detachInput(uint8_t *in);
    void detachOutput(Output *out);

private:
    Instructions instr;
    Stack stack;
    Flags flags;
    uint8_t ram[RAM_SIZE];
    uint8_t regs[REGS_NO];

private:
    bool intOccured;
};

#endif // CPU_H
