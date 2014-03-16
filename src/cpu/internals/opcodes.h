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

	Opcodes definition
*/

#ifndef OPCODES_H_INCLUDED
#define OPCODES_H_INCLUDED

enum INSTR
{
    INSTR_LOAD_CONST 	= 0x00,
    INSTR_LOAD_REG 		= 0x01,
    INSTR_INPUT_CONST 	= 0x04,
    INSTR_INPUT_REG 	= 0x05,
    INSTR_FETCH_CONST 	= 0x06,
    INSTR_FETCH_REG 	= 0x07,
    INSTR_AND_CONST 	= 0x0a,
    INSTR_AND_REG 		= 0x0b,
    INSTR_OR_CONST 		= 0x0c,
    INSTR_OR_REG 		= 0x0d,
    INSTR_XOR_CONST 	= 0x0e,
    INSTR_XOR_REG 		= 0x0f,
    INSTR_TEST_CONST 	= 0x12,
    INSTR_TEST_REG 		= 0x13,
    INSTR_COMPARE_CONST = 0x14,
    INSTR_COMPARE_REG 	= 0x15,
    INSTR_ADD_CONST 	= 0x18,
    INSTR_ADD_REG 		= 0x19,
    INSTR_ADDCY_CONST 	= 0x1a,
    INSTR_ADDCY_REG 	= 0x1b,
    INSTR_SUB_CONST 	= 0x1c,
    INSTR_SUB_REG 		= 0x1d,
    INSTR_SUBCY_CONST 	= 0x1e,
    INSTR_SUBCY_REG 	= 0x1f,
    INSTR_ROTATE_REG 	= 0x20,
    INSTR_RETURN 		= 0x2a,
    INSTR_RETURN_COND 	= 0x2b,
    INSTR_OUTPUT_CONST 	= 0x2c,
    INSTR_OUTPUT_REG 	= 0x2d,
    INSTR_STORE_CONST 	= 0x2e,
    INSTR_STORE_REG 	= 0x2f,
    INSTR_CALL 			= 0x30,
    INSTR_CALL_COND 	= 0x31,
    INSTR_JUMP 			= 0x34,
    INSTR_JUMP_COND 	= 0x35,
    INSTR_RETURNI 		= 0x38,
    INSTR_INTERRUPT 	= 0x3c
};

enum INSTR_ROTATE
{
    INSTR_RL_REG    = 0x02,
    INSTR_RR_REG    = 0x0c,
    INSTR_SL0_REG   = 0x06,
    INSTR_SL1_REG   = 0x07,
    INSTR_SLA_REG   = 0x00,
    INSTR_SLX_REG   = 0x04,
    INSTR_SR0_REG   = 0x0e,
    INSTR_SR1_REG   = 0x0f,
    INSTR_SRA_REG   = 0x08,
    INSTR_SRX_REG   = 0x0a
};

#endif // OPCODES_H_INCLUDED
