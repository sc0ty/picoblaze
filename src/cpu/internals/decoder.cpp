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

	Instruction decoding methods
*/

#include <cstdlib>

#include "instruction.h"
#include "../cpu.h"

void Instruction::do_ADD_sX_kk(Cpu &cpu)
{
    unsigned int rx = getRegX(cpu) + getConst();
    cpu.flags.cf = (rx > 0xff);
    cpu.flags.zf = ((rx & 0xff) == 0);
    setRegX(cpu, rx);
}

void Instruction::do_ADD_sX_sY(Cpu &cpu)
{
    unsigned int rx = getRegX(cpu) + getRegY(cpu);
    cpu.flags.cf = (rx > 0xff);
    cpu.flags.zf = ((rx & 0xff) == 0);
    setRegX(cpu, rx);
}

void Instruction::do_ADDCY_sX_kk(Cpu &cpu)
{
    unsigned int rx = getRegX(cpu) + getConst() + cpu.flags.cf;
    cpu.flags.cf = (rx > 0xff);
    cpu.flags.zf = ((rx & 0xff) == 0);
    setRegX(cpu, rx);
}

void Instruction::do_ADDCY_sX_sY(Cpu &cpu)
{
    unsigned int rx = getRegX(cpu) + getRegY(cpu) + cpu.flags.cf;
    cpu.flags.cf = (rx > 0xff);
    cpu.flags.zf = ((rx & 0xff) == 0);
    setRegX(cpu, rx);
}

void Instruction::do_AND_sX_kk(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu) & getConst();
    cpu.flags.cf = 0;
    cpu.flags.zf = (rx == 0);
    setRegX(cpu, rx);
}

void Instruction::do_AND_sX_sY(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu) & getRegY(cpu);
    cpu.flags.cf = 0;
    cpu.flags.zf = (rx == 0);
    setRegX(cpu, rx);
}

void Instruction::do_CALL(Cpu &cpu)
{
    cpu.stack.push(cpu.instr.pc);
    cpu.instr.pc = getInstrAddr() - 1;
}

void Instruction::do_CALL_X(Cpu &cpu)
{
    if (checkCondition(cpu))
        do_CALL(cpu);
}

void Instruction::do_COMPARE_sX_kk(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t kk = getConst();

    cpu.flags.cf = (kk > rx);
    cpu.flags.zf = (kk == rx);
}

void Instruction::do_COMPARE_sX_sY(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t kk = getRegY(cpu);

    cpu.flags.cf = (kk > rx);
    cpu.flags.zf = (kk == rx);
}

void Instruction::do_DISABLE_ENABLE_INTERRUPT(Cpu &cpu)
{
    cpu.flags.ie = (code & 1);
}

void Instruction::do_FETCH_sX__ss(Cpu &cpu)
{
    uint8_t rx = cpu.ram[ getRamAddr() ];
    setRegX(cpu, rx);
}

void Instruction::do_FETCH_sX_sY(Cpu &cpu)
{
    uint8_t rx = cpu.ram[ getRegY(cpu) ];
    setRegX(cpu, rx);
}

void Instruction::do_INPUT_sX_sY(Cpu &cpu)
{
    uint8_t ry = getRegY(cpu);
    setRegX(cpu, cpu.ins[ry].get());
}

void Instruction::do_INPUT_sX_pp(Cpu &cpu)
{
    uint8_t port = getPort();
    setRegX(cpu, cpu.ins[port].get());
}

void Instruction::do_JUMP(Cpu &cpu)
{
    cpu.instr.pc = getInstrAddr() - 1;
}

void Instruction::do_JUMP_X(Cpu &cpu)
{
    if (checkCondition(cpu))
        cpu.instr.pc = getInstrAddr() - 1;
}

void Instruction::do_LOAD_sX_kk(Cpu &cpu)
{
    setRegX(cpu, getConst());
}

void Instruction::do_LOAD_sX_sY(Cpu &cpu)
{
    setRegX(cpu, getRegY(cpu));
}

void Instruction::do_OR_sX_kk(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu) | getConst();
    cpu.flags.cf = 0;
    cpu.flags.zf = (rx == 0);
    setRegX(cpu, rx);
}

void Instruction::do_OR_sX_sY(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu) | getRegY(cpu);
    cpu.flags.cf = 0;
    cpu.flags.zf = (rx == 0);
    setRegX(cpu, rx);
}

void Instruction::do_OUTPUT_sX_sY(Cpu &cpu)
{
    uint8_t ry = getRegY(cpu);
    cpu.outs[ry].set(getRegX(cpu));
}

void Instruction::do_OUTPUT_sX_pp(Cpu &cpu)
{
    uint8_t port = getPort();
    cpu.outs[port].set(getRegX(cpu));
}

void Instruction::do_RETURN(Cpu &cpu)
{
    cpu.instr.pc = cpu.stack.pop();
}

void Instruction::do_RETURN_X(Cpu &cpu)
{
    if (checkCondition(cpu))
        cpu.instr.pc = cpu.stack.pop();
}

void Instruction::do_RETURNI_DISABLE_ENABLE(Cpu &cpu)
{
    cpu.flags.restore();
    cpu.flags.ie = code & 1;
    cpu.instr.pc = cpu.stack.pop();
}

void Instruction::do_ROTATE_sX(Cpu &cpu)
{
    executeRotate(cpu);
}

void Instruction::do_STORE_sX__ss(Cpu &cpu)
{
    unsigned int loc = getRegY(cpu) & 0x3f;
    cpu.ram[loc] = getConst();
}

void Instruction::do_STORE_sX_sY(Cpu &cpu)
{
    unsigned int loc = getRegY(cpu) & 0x3f;
    cpu.ram[loc] = getRegX(cpu);
}

void Instruction::do_SUB_sX_kk(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t kk = getConst();

    setRegX(cpu, rx - kk);
    cpu.flags.cf = (kk > rx);
    cpu.flags.zf = (kk == rx);
}

void Instruction::do_SUB_sX_sY(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t ry = getRegY(cpu);

    setRegX(cpu, rx - ry);
    cpu.flags.cf = (ry > rx);
    cpu.flags.zf = (ry == rx);
}


void Instruction::do_SUBCY_sX_kk(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t kk = getConst();

    setRegX(cpu, rx - kk - cpu.flags.cf);
    cpu.flags.cf = (rx < kk - cpu.flags.cf);
    cpu.flags.zf = (rx - kk - cpu.flags.cf) == 0;
}


void Instruction::do_SUBCY_sX_sY(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t ry = getRegY(cpu);

    setRegX(cpu, rx - ry - cpu.flags.cf);
    cpu.flags.cf = (rx < ry - cpu.flags.cf);
    cpu.flags.zf = (rx - ry - cpu.flags.cf) == 0;
}


void Instruction::do_TEST_sX_kk(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t kk = getConst();

    cpu.flags.zf = (rx & kk) == 0;
    cpu.flags.cf = (rx ^ kk);
}


void Instruction::do_TEST_sX_sY(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t ry = getRegY(cpu);

    cpu.flags.zf = (rx & ry) == 0;
    cpu.flags.cf = (rx ^ ry);
}

void Instruction::do_XOR_sX_kk(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t kk = getConst();

    setRegX(cpu, rx ^ kk);
    cpu.flags.zf = (rx ^ kk) == 0;
    cpu.flags.cf = 0;
}

void Instruction::do_XOR_sX_sY(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    uint8_t ry = getRegY(cpu);

    setRegX(cpu, rx ^ ry);
    cpu.flags.zf = (rx ^ ry) == 0;
    cpu.flags.cf = 0;
}

void Instruction::do_RL_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    bool cf = rx & 0x80;

    rx <<= 1;
    rx |= cf;

    setRegX(cpu, rx);
    cpu.flags.cf = cf;
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_RR_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    bool cf = rx & 1;

    rx >>= 1;
    rx |= (cf << 7);

    setRegX(cpu, rx);
    cpu.flags.cf = cf;
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_SL0_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    cpu.flags.cf = rx & 0x80;

    rx <<= 1;

    setRegX(cpu, rx);
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_SL1_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    cpu.flags.cf = rx & 0x80;

    rx <<= 1;
    rx |= 1;

    setRegX(cpu, rx);
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_SLA_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    cpu.flags.cf = rx & 0x80;

    rx <<= 1;
    rx |= cpu.flags.cf;

    setRegX(cpu, rx);
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_SLX_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    cpu.flags.cf = rx & 0x80;

    uint8_t bit0 = rx & 1;
    rx <<= 1;
    rx |= bit0;

    setRegX(cpu, rx);
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_SR0_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    cpu.flags.cf = rx & 1;

    rx >>= 1;

    setRegX(cpu, rx);
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_SR1_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    cpu.flags.cf = rx & 1;

    rx <<= 1;
    rx |= 0x80;

    setRegX(cpu, rx);
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_SRA_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    cpu.flags.cf = rx & 1;

    rx >>= 1;
    rx |= (cpu.flags.cf << 7);

    setRegX(cpu, rx);
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_SRX_sX(Cpu &cpu)
{
    uint8_t rx = getRegX(cpu);
    cpu.flags.cf = rx & 1;

    uint8_t bit7 = rx & 0x80;
    rx >>= 1;
    rx |= bit7;

    setRegX(cpu, rx);
    cpu.flags.zf = (rx == 0);
}

void Instruction::do_UNDEF(Cpu &cpu)
{
}
