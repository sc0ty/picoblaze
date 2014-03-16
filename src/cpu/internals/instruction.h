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

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstddef>
#include <stdint.h>

class Cpu;
class Instruction;

typedef void (Instruction::*OpcodeMethod)(Cpu &cpu);

class Instruction
{
public:
    Instruction();
    virtual ~Instruction();

    uint32_t getCode();
    void setCode(uint32_t code);

    void execute(Cpu &cpu);
    bool isUndefined();

    // helper methods
protected:
    void executeRotate(Cpu &cpu);

    uint32_t getOpCode();
    unsigned int getInstrAddr();
    unsigned int getConst();
    unsigned int getPort();
    unsigned int getRamAddr();
    uint8_t getRegX(Cpu &cpu);
    uint8_t getRegY(Cpu &cpu);
    void setRegX(Cpu &cpu, uint8_t value);
    void setRegY(Cpu &cpu, uint8_t value);
    bool checkCondition(Cpu &cpu);

    // opcodes
protected:
    void do_ADD_sX_kk(Cpu &cpu);
    void do_ADD_sX_sY(Cpu &cpu);
    void do_ADDCY_sX_kk(Cpu &cpu);
    void do_ADDCY_sX_sY(Cpu &cpu);
    void do_AND_sX_kk(Cpu &cpu);
    void do_AND_sX_sY(Cpu &cpu);
    void do_CALL(Cpu &cpu);
    void do_CALL_X(Cpu &cpu);
    void do_COMPARE_sX_kk(Cpu &cpu);
    void do_COMPARE_sX_sY(Cpu &cpu);
    void do_DISABLE_ENABLE_INTERRUPT(Cpu &cpu);
    void do_FETCH_sX__ss(Cpu &cpu);
    void do_FETCH_sX_sY(Cpu &cpu);
    void do_INPUT_sX_sY(Cpu &cpu);
    void do_INPUT_sX_pp(Cpu &cpu);
    void do_JUMP(Cpu &cpu);
    void do_JUMP_X(Cpu &cpu);
    void do_LOAD_sX_kk(Cpu &cpu);
    void do_LOAD_sX_sY(Cpu &cpu);
    void do_OR_sX_kk(Cpu &cpu);
    void do_OR_sX_sY(Cpu &cpu);
    void do_OUTPUT_sX_sY(Cpu &cpu);
    void do_OUTPUT_sX_pp(Cpu &cpu);
    void do_RETURN(Cpu &cpu);
    void do_RETURN_X(Cpu &cpu);
    void do_RETURNI_DISABLE_ENABLE(Cpu &cpu);
    void do_ROTATE_sX(Cpu &cpu);
    void do_STORE_sX__ss(Cpu &cpu);
    void do_STORE_sX_sY(Cpu &cpu);
    void do_SUB_sX_kk(Cpu &cpu);
    void do_SUB_sX_sY(Cpu &cpu);
    void do_SUBCY_sX_kk(Cpu &cpu);
    void do_SUBCY_sX_sY(Cpu &cpu);
    void do_TEST_sX_kk(Cpu &cpu);
    void do_TEST_sX_sY(Cpu &cpu);
    void do_XOR_sX_kk(Cpu &cpu);
    void do_XOR_sX_sY(Cpu &cpu);

    void do_RL_sX(Cpu &cpu);
    void do_RR_sX(Cpu &cpu);
    void do_SL0_sX(Cpu &cpu);
    void do_SL1_sX(Cpu &cpu);
    void do_SLA_sX(Cpu &cpu);
    void do_SLX_sX(Cpu &cpu);
    void do_SR0_sX(Cpu &cpu);
    void do_SR1_sX(Cpu &cpu);
    void do_SRA_sX(Cpu &cpu);
    void do_SRX_sX(Cpu &cpu);

    void do_UNDEF(Cpu &cpu);

protected:
    uint32_t code;
};

#endif // INSTRUCTION_H
