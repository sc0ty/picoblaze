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

	Instruction disassembling class
*/

#include <sstream>
#include <iomanip>

#include "internals/opcodes.h"
#include "disasm.h"

using namespace std;

DisAsm::DisAsm()
{
}

DisAsm::~DisAsm()
{
}

string DisAsm::toString(unsigned int align)
{
    string name = this->getName();
    string param1 = this->getParam1();
    string param2 = this->getParam2();

    string result = name;

    if ((align) && (name.length() < align))
        result.append(align-name.length(), ' ');

    else if (!param1.empty())
        result += ' ';

    if (!param1.empty())
    {
        result += param1;

        if (!param2.empty())
            result += ",  " + param2;
    }

    return result;
}

string DisAsm::getName()
{
    switch (this->getOpCode())
    {
    case INSTR_LOAD_CONST:
    case INSTR_LOAD_REG:
        return "LOAD";
        break;
    case INSTR_INPUT_CONST:
    case INSTR_INPUT_REG:
        return "IN";
        break;
    case INSTR_FETCH_CONST:
    case INSTR_FETCH_REG:
        return "FETCH";
        break;
    case INSTR_AND_CONST:
    case INSTR_AND_REG:
        return "AND";
        break;
    case INSTR_OR_CONST:
    case INSTR_OR_REG:
        return "OR";
        break;
    case INSTR_XOR_CONST:
    case INSTR_XOR_REG:
        return "XOR";
        break;
    case INSTR_TEST_CONST:
    case INSTR_TEST_REG:
        return "TEST";
        break;
    case INSTR_COMPARE_CONST:
    case INSTR_COMPARE_REG:
        return "COMP";
        break;
    case INSTR_ADD_CONST:
    case INSTR_ADD_REG:
        return "ADD";
        break;
    case INSTR_ADDCY_CONST:
    case INSTR_ADDCY_REG:
        return "ADDC";
        break;
    case INSTR_SUB_CONST:
    case INSTR_SUB_REG:
        return "SUB";
        break;
    case INSTR_SUBCY_CONST:
    case INSTR_SUBCY_REG:
        return "SUBC";
        break;
    case INSTR_ROTATE_REG:
        return this->getNameRotate();
    case INSTR_RETURN:
    case INSTR_RETURN_COND:
        return "RET";
        break;
    case INSTR_OUTPUT_CONST:
    case INSTR_OUTPUT_REG:
        return "OUT";
        break;
    case INSTR_STORE_CONST:
    case INSTR_STORE_REG:
        return "STORE";
        break;
    case INSTR_CALL:
    case INSTR_CALL_COND:
        return "CALL";
        break;
    case INSTR_JUMP:
    case INSTR_JUMP_COND:
        return "JUMP";
        break;
    case INSTR_RETURNI:
        return "RETI";
        break;
    case INSTR_INTERRUPT:
        return (code & 1) ? "EINT": "DINT";
        break;
    }

    return "UNDEFINED";
}

string DisAsm::getParam1()
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
            (opc == INSTR_ROTATE_REG) || (opc == INSTR_OUTPUT_CONST) ||
            (opc == INSTR_OUTPUT_REG) || (opc == INSTR_STORE_CONST) ||
            (opc == INSTR_STORE_REG))
        return this->strRegX();

    if ((opc == INSTR_RETURN_COND) || (opc == INSTR_CALL_COND) ||
            (opc == INSTR_JUMP_COND))
        return this->strCondition();

    if ((opc == INSTR_CALL) || (opc == INSTR_JUMP))
        return this->strInstrAddr();

    if (opc == INSTR_RETURNI)
    {
        if (this->code & 1)
            return "ENABLE";
        else
            return "DISABLE";
    }

    return "";
}

string DisAsm::getParam2()
{
    unsigned int opc = this->getOpCode();

    if ((opc == INSTR_LOAD_CONST) || (opc == INSTR_AND_CONST) ||
            (opc == INSTR_OR_CONST) || (opc == INSTR_XOR_CONST) ||
            (opc == INSTR_TEST_CONST) || (opc == INSTR_COMPARE_CONST) ||
            (opc == INSTR_ADD_CONST) || (opc == INSTR_ADDCY_CONST) ||
            (opc == INSTR_SUB_CONST) || (opc == INSTR_SUBCY_CONST))
        return this->strConst();

    if ((opc == INSTR_INPUT_CONST) || (opc == INSTR_OUTPUT_CONST))
        return this->strPort();

    if ((opc == INSTR_FETCH_CONST) || (opc == INSTR_STORE_CONST))
        return this->strRamAdr();

    if ((opc == INSTR_LOAD_REG) || (opc == INSTR_INPUT_REG) ||
            (opc == INSTR_FETCH_REG) || (opc == INSTR_AND_REG) ||
            (opc == INSTR_OR_REG) || (opc == INSTR_XOR_REG) ||
            (opc == INSTR_TEST_REG) || (opc == INSTR_COMPARE_REG) ||
            (opc == INSTR_ADD_REG) || (opc == INSTR_ADDCY_REG) ||
            (opc == INSTR_SUB_REG) || (opc == INSTR_SUBCY_REG) ||
            (opc == INSTR_OUTPUT_REG) || (opc == INSTR_STORE_REG))
        return this->strRegY();

    if ((opc == INSTR_CALL_COND) || (opc == INSTR_JUMP_COND))
        return this->strInstrAddr();

    return "";
}

string DisAsm::getNameRotate()
{
    switch (this->code & 0x0f)
    {
    case INSTR_RL_REG:
        return "RL";
        break;
    case INSTR_RR_REG:
        return "RR";
        break;
    case INSTR_SL0_REG:
        return "SL0";
        break;
    case INSTR_SL1_REG:
        return "SL1";
        break;
    case INSTR_SLA_REG:
        return "SLA";
        break;
    case INSTR_SLX_REG:
        return "SLX";
        break;
    case INSTR_SR0_REG:
        return "SR0";
        break;
    case INSTR_SR1_REG:
        return "SR1";
        break;
    case INSTR_SRA_REG:
        return "SRA";
        break;
    case INSTR_SRX_REG:
        return "SRX";
        break;
    }

    return "UNDEFINED";
}

string DisAsm::strConst()
{
    stringstream ss;
    ss << hex << setfill('0') << setw(2) << this->getConst();
    return ss.str();
}

string DisAsm::strPort()
{
    stringstream ss;
    ss << hex << setfill('0') << setw(2) << this->getPort();
    return ss.str();
}

string DisAsm::strRamAdr()
{
    stringstream ss;
    ss << hex << setfill('0') << setw(2) << this->getRamAddr();
    return ss.str();
}

string DisAsm::strRegX()
{
    stringstream ss;
    unsigned int reg;

    reg = this->code >> 8;
    reg &= 0x0f;

    ss << "s" << uppercase << hex << reg;
    return ss.str();
}

string DisAsm::strRegY()
{
    stringstream ss;
    unsigned int reg;

    reg = this->code >> 4;
    reg &= 0x0f;

    ss << "s" << uppercase << hex << reg;
    return ss.str();
}

string DisAsm::strCondition()
{
    string s;
    unsigned int condition = this->code & (3 << 10);

    switch (condition)
    {
    case (0 << 10):
        s = "Z";
        break;
    case (1 << 10):
        s = "NZ";
        break;
    case (2 << 10):
        s = "C";
        break;
    case (3 << 10):
        s = "NC";
        break;
    }

    return s;
}

string DisAsm::strInstrAddr()
{
    stringstream ss;
    ss << uppercase << hex << setfill('0') << setw(3) << this->getInstrAddr();
    return ss.str();
}

