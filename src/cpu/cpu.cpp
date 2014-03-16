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

#include <cstring>

#include "cpu.h"
#include "internals/instruction.h"
#include "fileloader.h"

Cpu::Cpu() : intOccured(false)
{
    this->instr.allocate(INSTRUCTIONS_NO);
    this->stack.allocate(STACK_SIZE);

    this->clear();
}

Cpu::~Cpu()
{
    this->instr.free();
    this->stack.free();
}

void Cpu::loadHex(const char *fileName)
{
    unsigned int size = this->instr.getSize();

    uint32_t *buf = new uint32_t[size];
    memset((void*)buf, 0, size);

    loadHexFile(fileName, buf, size);
    this->instr.load(buf, size);

    delete [] buf;
}

void Cpu::execute()
{
    if (this->intOccured)
    {
        this->intOccured = false;
        this->instr.interrupt(*this);
    }

    else
    {
        this->instr.execute(*this);
    }
}

void Cpu::reset()
{
    this->instr.reset();
    this->flags.reset();
    this->stack.reset();
    this->intOccured = false;
}

void Cpu::generateInt()
{
    if (this->flags.ie)
        this->intOccured = true;
}

uint8_t Cpu::getRegister(unsigned int no)
{
    if (no < REGS_NO)
        return this->regs[no];
    else
        return 0;
}

void Cpu::setRegister(unsigned int no, uint8_t value)
{
    if (no < REGS_NO)
        this->regs[no] = value;
}

uint8_t Cpu::getRam(unsigned int addr)
{
    if (addr < RAM_SIZE)
        return this->ram[addr];
    else
        return 0;
}

void Cpu::setRam(unsigned int addr, uint8_t value)
{
    if (addr < RAM_SIZE)
        this->ram[addr] = value;
}

unsigned int Cpu::getStack(unsigned int addr)
{
    return this->stack.getValue(addr);
}

void Cpu::setStack(unsigned int addr, unsigned int value)
{
    this->stack.setValue(addr, value);
}

unsigned int Cpu::getPC()
{
    return this->instr.getPC();
}

void Cpu::setPC(unsigned int pc)
{
    this->instr.setPC(pc);
}

unsigned int Cpu::getSP()
{
    return this->stack.getSP();
}

void Cpu::setSP(unsigned int sp)
{
    this->stack.setSP(sp);
}

bool Cpu::getCF()
{
    return this->flags.cf;
}

void Cpu::setCF(bool f)
{
    this->flags.cf = f;
}

bool Cpu::getZF()
{
    return this->flags.zf;
}

void Cpu::setZF(bool f)
{
    this->flags.zf = f;
}

bool Cpu::getIE()
{
    return this->flags.ie;
}

void Cpu::setIE(bool f)
{
    this->flags.ie = f;
}

void Cpu::clearRegisters()
{
    memset(this->regs, 0, REGS_NO*sizeof(uint8_t));
}

void Cpu::clearRam()
{
    memset(this->ram, 0, RAM_SIZE*sizeof(uint8_t));
}

void Cpu::clearStack()
{
    this->stack.clear();
}

void Cpu::clearFlags()
{
    this->flags.reset();
}

void Cpu::clear()
{
    this->clearRegisters();
    this->clearRam();
    this->clearStack();
    this->clearFlags();
    this->reset();
}

uint32_t Cpu::getInstructionCode(unsigned int addr)
{
    Instruction *i = this->instr.getInstruction(addr);

    if (i != NULL)
        return i->getCode();
    else
        return 0;
}

void Cpu::setInstructionCode(unsigned int addr, uint32_t code)
{
    Instruction *i = this->instr.getInstruction(addr);

    if (i != NULL)
        i->setCode(code);
}

void Cpu::detachInput(uint8_t *in)
{
    if (in != NULL)
    {
        unsigned int i;

        for (i=0; i<IO_PORTS_NO; ++i)
        {
            this->ins[i].detach(in);
        }
    }
}

void Cpu::detachOutput(Output *out)
{
    if (out != NULL)
    {
        unsigned int i;

        for (i=0; i<IO_PORTS_NO; ++i)
        {
            this->outs[i].detach(out);
        }
    }
}
