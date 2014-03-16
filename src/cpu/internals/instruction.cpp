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

	Single instruction execution
*/

#include <cstddef>
#include <cstdlib>

#include "opcodes.h"
#include "instruction.h"
#include "../cpu.h"

Instruction::Instruction() : code(0)
{
}

Instruction::~Instruction()
{
}

uint32_t Instruction::getCode()
{
    return this->code;
}

void Instruction::setCode(uint32_t code)
{
    this->code = code & 0x3ffff;
}

void Instruction::execute(Cpu &cpu)
{

#ifdef LOOKUP_TABLE_INSTRUCTION_DECODER

    // instructions lookup table
    static const OpcodeMethod opcodeMethods[64] =
    {
        &Instruction::do_LOAD_sX_kk,
        &Instruction::do_LOAD_sX_sY,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_INPUT_sX_pp,
        &Instruction::do_INPUT_sX_sY,
        &Instruction::do_FETCH_sX__ss,
        &Instruction::do_FETCH_sX_sY,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_AND_sX_kk,
        &Instruction::do_AND_sX_sY,
        &Instruction::do_OR_sX_kk,
        &Instruction::do_OR_sX_sY,
        &Instruction::do_XOR_sX_kk,
        &Instruction::do_XOR_sX_sY,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_TEST_sX_kk,
        &Instruction::do_TEST_sX_sY,
        &Instruction::do_COMPARE_sX_kk,
        &Instruction::do_COMPARE_sX_sY,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_ADD_sX_kk,
        &Instruction::do_ADD_sX_sY,
        &Instruction::do_ADDCY_sX_kk,
        &Instruction::do_ADDCY_sX_sY,
        &Instruction::do_SUB_sX_kk,
        &Instruction::do_SUB_sX_sY,
        &Instruction::do_SUBCY_sX_kk,
        &Instruction::do_SUBCY_sX_sY,
        &Instruction::do_ROTATE_sX,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_RETURN,
        &Instruction::do_RETURN_X,
        &Instruction::do_OUTPUT_sX_pp,
        &Instruction::do_OUTPUT_sX_sY,
        &Instruction::do_STORE_sX__ss,
        &Instruction::do_STORE_sX_sY,
        &Instruction::do_CALL,
        &Instruction::do_CALL_X,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_JUMP,
        &Instruction::do_JUMP_X,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_RETURNI_DISABLE_ENABLE,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_DISABLE_ENABLE_INTERRUPT,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF,
        &Instruction::do_UNDEF
    };

    // call method from lookup table
    (this->*opcodeMethods[ this->getOpCode() ])(cpu);

#else // SWITCH INSTRUCTION DECODER

    switch (this->getOpCode())
    {
    case INSTR_LOAD_CONST:
        do_LOAD_sX_kk(cpu);
        break;
    case INSTR_LOAD_REG:
        do_LOAD_sX_sY(cpu);
        break;
    case INSTR_INPUT_CONST:
        do_INPUT_sX_pp(cpu);
        break;
    case INSTR_INPUT_REG:
        do_INPUT_sX_sY(cpu);
        break;
    case INSTR_FETCH_CONST:
        do_FETCH_sX__ss(cpu);
        break;
    case INSTR_FETCH_REG:
        do_FETCH_sX_sY(cpu);
        break;
    case INSTR_AND_CONST:
        do_AND_sX_kk(cpu);
        break;
    case INSTR_AND_REG:
        do_AND_sX_sY(cpu);
        break;
    case INSTR_OR_CONST:
        do_OR_sX_kk(cpu);
        break;
    case INSTR_OR_REG:
        do_OR_sX_sY(cpu);
        break;
    case INSTR_XOR_CONST:
        do_XOR_sX_kk(cpu);
        break;
    case INSTR_XOR_REG:
        do_XOR_sX_sY(cpu);
        break;
    case INSTR_TEST_CONST:
        do_TEST_sX_kk(cpu);
        break;
    case INSTR_TEST_REG:
        do_TEST_sX_sY(cpu);
        break;
    case INSTR_COMPARE_CONST:
        do_COMPARE_sX_kk(cpu);
        break;
    case INSTR_COMPARE_REG:
        do_COMPARE_sX_sY(cpu);
        break;
    case INSTR_ADD_CONST:
        do_ADD_sX_kk(cpu);
        break;
    case INSTR_ADD_REG:
        do_ADD_sX_sY(cpu);
        break;
    case INSTR_ADDCY_CONST:
        do_ADDCY_sX_kk(cpu);
        break;
    case INSTR_ADDCY_REG:
        do_ADDCY_sX_sY(cpu);
        break;
    case INSTR_SUB_CONST:
        do_SUB_sX_kk(cpu);
        break;
    case INSTR_SUB_REG:
        do_SUB_sX_sY(cpu);
        break;
    case INSTR_SUBCY_CONST:
        do_SUBCY_sX_kk(cpu);
        break;
    case INSTR_SUBCY_REG:
        do_SUBCY_sX_sY(cpu);
        break;
    case INSTR_ROTATE_REG:
        do_ROTATE_sX(cpu);
        break;
    case INSTR_RETURN:
        do_RETURN(cpu);
        break;
    case INSTR_RETURN_COND:
        do_RETURN_X(cpu);
        break;
    case INSTR_OUTPUT_CONST:
        do_OUTPUT_sX_pp(cpu);
        break;
    case INSTR_OUTPUT_REG:
        do_OUTPUT_sX_sY(cpu);
        break;
    case INSTR_STORE_CONST:
        do_STORE_sX__ss(cpu);
        break;
    case INSTR_STORE_REG:
        do_STORE_sX_sY(cpu);
        break;
    case INSTR_CALL:
        do_CALL(cpu);
        break;
    case INSTR_CALL_COND:
        do_CALL_X(cpu);
        break;
    case INSTR_JUMP:
        do_JUMP(cpu);
        break;
    case INSTR_JUMP_COND:
        do_JUMP_X(cpu);
        break;
    case INSTR_RETURNI:
        do_RETURNI_DISABLE_ENABLE(cpu);
        break;
    case INSTR_INTERRUPT:
        do_DISABLE_ENABLE_INTERRUPT(cpu);
        break;
    default:
        do_UNDEF(cpu);
    }

#endif
}

void Instruction::executeRotate(Cpu &cpu)
{

#ifdef LOOKUP_TABLE_INSTRUCTION_DECODER

    // rotate/shift instructions lookup table
    static const OpcodeMethod opcodeMethods[16] =
    {
        &Instruction::do_SLA_sX,
        &Instruction::do_UNDEF,
        &Instruction::do_RL_sX,
        &Instruction::do_UNDEF,
        &Instruction::do_SLX_sX,
        &Instruction::do_UNDEF,
        &Instruction::do_SL0_sX,
        &Instruction::do_SL1_sX,
        &Instruction::do_SRA_sX,
        &Instruction::do_UNDEF,
        &Instruction::do_SRX_sX,
        &Instruction::do_UNDEF,
        &Instruction::do_RR_sX,
        &Instruction::do_UNDEF,
        &Instruction::do_SR0_sX,
        &Instruction::do_SR1_sX
    };

    // call method from lookup table
    (this->*opcodeMethods[ code & 0x0f ])(cpu);

#else

    switch (this->code & 0x0f)
    {
    case INSTR_RL_REG:
        do_RL_sX(cpu);
        break;
    case INSTR_RR_REG:
        do_RR_sX(cpu);
        break;
    case INSTR_SL0_REG:
        do_SL0_sX(cpu);
        break;
    case INSTR_SL1_REG:
        do_SL1_sX(cpu);
        break;
    case INSTR_SLA_REG:
        do_SLA_sX(cpu);
        break;
    case INSTR_SLX_REG:
        do_SLX_sX(cpu);
        break;
    case INSTR_SR0_REG:
        do_SR0_sX(cpu);
        break;
    case INSTR_SR1_REG:
        do_SR1_sX(cpu);
        break;
    case INSTR_SRA_REG:
        do_SRA_sX(cpu);
        break;
    case INSTR_SRX_REG:
        do_SRX_sX(cpu);
        break;
    default:
        do_UNDEF(cpu);
    }

#endif
}

bool Instruction::isUndefined()
{
    unsigned int opc = this->getOpCode();

    if ((opc == INSTR_LOAD_CONST) || (opc == INSTR_LOAD_REG) ||
            (opc == INSTR_INPUT_CONST) || (opc == INSTR_INPUT_REG) ||
            (opc == INSTR_FETCH_CONST) || (opc == INSTR_FETCH_REG) ||
            (opc == INSTR_AND_CONST) || (opc == INSTR_AND_REG) ||
            (opc == INSTR_OR_CONST) || (opc == INSTR_OR_REG) ||
            (opc == INSTR_XOR_CONST) || (opc == INSTR_XOR_REG) ||
            (opc == INSTR_TEST_CONST) || (opc == INSTR_TEST_REG) ||
            (opc == INSTR_COMPARE_CONST) || (opc == INSTR_COMPARE_REG) ||
            (opc == INSTR_ADD_CONST) || (opc == INSTR_ADD_REG) ||
            (opc == INSTR_ADDCY_CONST) || (opc == INSTR_ADDCY_REG) ||
            (opc == INSTR_SUB_CONST) || (opc == INSTR_SUB_REG) ||
            (opc == INSTR_SUBCY_CONST) || (opc == INSTR_SUBCY_REG) ||
            (opc == INSTR_ROTATE_REG) || (opc == INSTR_RETURN) ||
            (opc == INSTR_RETURN_COND) || (opc == INSTR_OUTPUT_CONST) ||
            (opc == INSTR_OUTPUT_REG) || (opc == INSTR_STORE_CONST) ||
            (opc == INSTR_STORE_REG) || (opc == INSTR_CALL) ||
            (opc == INSTR_CALL_COND) || (opc == INSTR_JUMP) ||
            (opc == INSTR_JUMP_COND) || (opc == INSTR_RETURNI) ||
            (opc == INSTR_INTERRUPT))
        return false;

    return true;
}

unsigned int Instruction::getOpCode()
{
    return this->code >> 12;
}

unsigned int Instruction::getInstrAddr()
{
    return this->code & 0x3ff;
}

unsigned int Instruction::getConst()
{
    return this->code & 0xff;
}

unsigned int Instruction::getPort()
{
    return this->code & 0xff;
}

unsigned int Instruction::getRamAddr()
{
    return this->code & 0x3f;
}

uint8_t Instruction::getRegX(Cpu &cpu)
{
    unsigned int reg;
    reg = this->code >> 8;
    reg &= 0x0f;

    return cpu.regs[reg];
}

uint8_t Instruction::getRegY(Cpu &cpu)
{
    unsigned int reg;
    reg = this->code >> 4;
    reg &= 0x0f;

    return cpu.regs[reg];
}

void Instruction::setRegX(Cpu &cpu, uint8_t value)
{
    unsigned int reg;
    reg = this->code >> 8;
    reg &= 0x0f;

    cpu.regs[reg] = value;
}

void Instruction::setRegY(Cpu &cpu, uint8_t value)
{
    unsigned int reg;
    reg = this->code >> 4;
    reg &= 0x0f;

    cpu.regs[reg] = value;
}

bool Instruction::checkCondition(Cpu &cpu)
{
    unsigned int condition = this->code & (3 << 10);

    switch (condition)
    {
    case (0 << 10):
        return cpu.flags.zf;
        break;
    case (1 << 10):
        return !cpu.flags.zf;
        break;
    case (2 << 10):
        return cpu.flags.cf;
        break;
    case (3 << 10):
        return !cpu.flags.cf;
        break;
    }

    return false;
}
