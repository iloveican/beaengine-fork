/* Copyright 2006-2009, BeatriX
 * File coded by BeatriX
 *
 * This file is part of BeaEngine.
 *
 *    BeaEngine is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    BeaEngine is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with BeaEngine.  If not, see <http://www.gnu.org/licenses/>. */

void __bea_callspec__ FailDecode(PDISASM pMyDisasm)
{
    GV.ERROR_OPCODE = 1;
}

/* ====================================================================
 *     37h
 * ==================================================================== */
void __bea_callspec__ aaa_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AAA;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    }
}

/* ====================================================================
 *     0d5h
 * ==================================================================== */
void __bea_callspec__ aad_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AAD;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        if (!Security1(pMyDisasm)) return;
        if (*((UInt8*)(UIntPtr) (GV.EIP_)) != 0x0A) {
            (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_+=1;
    };
}

/* ====================================================================
 *     0d4h
 * ==================================================================== */
void __bea_callspec__ aam_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AAM;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        if (!Security1(pMyDisasm)) return;
        if (*((UInt8*)(UIntPtr) (GV.EIP_)) != 0x0A) {
            (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_+=1;
    };
}

/* =======================================
 *     3fh
 * ======================================= */
void __bea_callspec__ aas_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_AAS;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    };
}

/* =======================================
 *      00h
 * ======================================= */
void __bea_callspec__ add_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADD;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      01h
 * ======================================= */
void __bea_callspec__ add_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADD;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      02h
 * ======================================= */
void __bea_callspec__ add_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADD;
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      03h
 * ======================================= */
void __bea_callspec__ add_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADD;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      04h
 * ======================================= */
void __bea_callspec__ add_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADD;
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      05h
 * ======================================= */
void __bea_callspec__ add_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADD;
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADD);
}

/* =======================================
 *      10h
 * ======================================= */
void __bea_callspec__ adc_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADC;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      11h
 * ======================================= */
void __bea_callspec__ adc_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADC;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      12h
 * ======================================= */
void __bea_callspec__ adc_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADC;
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      13h
 * ======================================= */
void __bea_callspec__ adc_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADC;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      14h
 * ======================================= */
void __bea_callspec__ adc_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADC;
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      15h
 * ======================================= */
void __bea_callspec__ adc_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_ADC;
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_ADC);
}

/* =======================================
 *      20h
 * ======================================= */
void __bea_callspec__ and_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_AND;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      21h
 * ======================================= */
void __bea_callspec__ and_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_AND;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      22h
 * ======================================= */
void __bea_callspec__ and_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_AND;
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *      23h
 * ======================================= */
void __bea_callspec__ and_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_AND;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *      24h
 * ======================================= */
void __bea_callspec__ and_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_AND;
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *      25h
 * ======================================= */
void __bea_callspec__ and_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_AND;
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_AND);
}

/* =======================================
 *     63h
 * ======================================= */
void __bea_callspec__ arpl_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOVSXD;
        GvEd(pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_MOVSX);
    }
    else {
        (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_ARPL;
        (*pMyDisasm).Instruction.OperandSize = 16;
        EvGv(pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_ARPL);
    }
}

/* =======================================
 *      62h
 * ======================================= */
void __bea_callspec__ bound_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_BOUND;
        GvEv(pMyDisasm);
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm, EFLAGS_BOUND);
    }
}

/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_eax(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_BSWAP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ecx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_BSWAP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_edx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_BSWAP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ebx(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_BSWAP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_esp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_BSWAP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ebp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_BSWAP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_esi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_BSWAP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);
}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_edi(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_BSWAP;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
    }
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_BSWAP);

}

/* =======================================
 *      0fbch
 * ======================================= */
void __bea_callspec__ bsf_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_BSF;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_BSCAN);
}

/* =======================================
 *      0fbdh
 * ======================================= */
void __bea_callspec__ bsr_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_BSR;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_BSCAN);
}

/* =======================================
 *      0fbbh
 * ======================================= */
void __bea_callspec__ btc_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_BTC;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_BTEST);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      0fa3h
 * ======================================= */
void __bea_callspec__ bt_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_BT;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_BTEST);
}

/* =======================================
 *      0fb3h
 * ======================================= */
void __bea_callspec__ btr_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_BTR;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_BTEST);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      0fabh
 * ======================================= */
void __bea_callspec__ bts_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (*pMyDisasm).Instruction.Mnemonic = I_BTS;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_BTEST);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      e8h
 * ======================================= */
void __bea_callspec__ call_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = CallType;
    (*pMyDisasm).Instruction.Mnemonic = I_CALL;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_))+5+(*pMyDisasm).Prefix.Number;
        CalculateRelativeAddress(&MyAddress,(Int64) MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_+=4;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_))+3+(*pMyDisasm).Prefix.Number;
        CalculateRelativeAddress(&MyAddress,(Int64) MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        GV.EIP_+=2;
    }
}

/* =======================================
 *     9ah
 * ======================================= */
void __bea_callspec__ callf_(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    UInt64 MyAddress;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = CallType;
        (*pMyDisasm).Instruction.Mnemonic = I_CALL_FAR;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize+16;
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            if (!Security(6, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+4));
            (*pMyDisasm).Argument1.SegmentReg = MyNumber;
            MyAddress = MyNumber*16;
            MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            GV.EIP_+=6;
        }
        else {
            if (!Security(4, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+2));
            (*pMyDisasm).Argument1.SegmentReg = MyNumber;
            MyAddress = MyNumber*16;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            GV.EIP_+=4;
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+FARPTR_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        (*pMyDisasm).Instruction.AddrValue = MyAddress + MyNumber;
    }
}

/* =======================================
 *      99h
 * ======================================= */
void __bea_callspec__ cdq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 64) {
        (*pMyDisasm).Instruction.Mnemonic = I_CQO;
    }
    else if ((*pMyDisasm).Instruction.OperandSize ==32) {
        (*pMyDisasm).Instruction.Mnemonic = I_CDQ;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_CWD;
    }
}

/* =======================================
 *     0f06h
 * ======================================= */
void __bea_callspec__ clts_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CLTS;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+CR_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, EFLAGS_CLTS);
}


/* =======================================
 *      F5h
 * ======================================= */
void __bea_callspec__ cmc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CMC;
    FillFlags(pMyDisasm, EFLAGS_CMC);
}

/* =======================================
 *     0f40h
 * ======================================= */
void __bea_callspec__ cmovo_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_O;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVO;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccO);
}

/* =======================================
 *     0f41h
 * ======================================= */
void __bea_callspec__ cmovno_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_NO;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVNO;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccNO);
}

/* =======================================
 *     0f42h
 * ======================================= */
void __bea_callspec__ cmovb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_B;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVB;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccB);
}

/* =======================================
 *     0f43h
 * ======================================= */
void __bea_callspec__ cmovae_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_AE;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVAE;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccAE);
}

/* =======================================
 *     0f44h
 * ======================================= */
void __bea_callspec__ cmove_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVE;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccE);
}

/* =======================================
 *     0f45h
 * ======================================= */
void __bea_callspec__ cmovne_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVNE;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccNE);
}

/* =======================================
 *     0f46h
 * ======================================= */
void __bea_callspec__ cmovbe_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_BE;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVBE;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccBE);
}

/* =======================================
 *     0f47h
 * ======================================= */
void __bea_callspec__ cmova_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_A;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVA;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccA);
}

/* =======================================
 *     0f48h
 * ======================================= */
void __bea_callspec__ cmovs_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_S;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVS;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccS);
}

/* =======================================
 *     0f49h
 * ======================================= */
void __bea_callspec__ cmovns_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_NS;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVNS;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccNS);
}

/* =======================================
 *     0f4ah
 * ======================================= */
void __bea_callspec__ cmovp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_P;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVP;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccP);
}

/* =======================================
 *     0f4bh
 * ======================================= */
void __bea_callspec__ cmovnp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_NP;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVNP;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccNP);
}

/* =======================================
 *     0f4ch
 * ======================================= */
void __bea_callspec__ cmovl_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_L;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVL;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccL);
}

/* =======================================
 *     0f4dh
 * ======================================= */
void __bea_callspec__ cmovge_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_GE;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVGE;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccGE);
}

/* =======================================
 *     0f4eh
 * ======================================= */
void __bea_callspec__ cmovle_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_LE;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVLE;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccLE);
}

/* =======================================
 *     0f4fh
 * ======================================= */
void __bea_callspec__ cmovg_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.ConditionalType = CC_G;
    (*pMyDisasm).Instruction.Mnemonic = I_CMOVG;
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_ccG);
}

/* =======================================
 *     0fb0h
 * ======================================= */
void __bea_callspec__ cmpx_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_CMPXCHG;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_CMPXCHG);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *    0fb1h
 * ======================================= */
void __bea_callspec__ cmpx_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_CMPXCHG;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_CMPXCHG);

    if ((*pMyDisasm).Prefix.LockState == InvalidPrefix && (*pMyDisasm).Argument1.ArgType & MEMORY_TYPE) {
        (*pMyDisasm).Prefix.LockState = InUsePrefix;
    }
}

/* =======================================
 *      38h
 * ======================================= */
void __bea_callspec__ cmp_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CMP;
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      39h
 * ======================================= */
void __bea_callspec__ cmp_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CMP;
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      3ah
 * ======================================= */
void __bea_callspec__ cmp_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CMP;
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      3bh
 * ======================================= */
void __bea_callspec__ cmp_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CMP;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      3ch
 * ======================================= */
void __bea_callspec__ cmp_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CMP;
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      3dh
 * ======================================= */
void __bea_callspec__ cmp_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CMP;
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm, EFLAGS_CMP);
}

/* =======================================
 *      a6h
 * ======================================= */
void __bea_callspec__ cmpsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Argument1.AccessMode = READ;
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        /* if there is a prefix override, mnemonic should be "cmps" */
        (*pMyDisasm).Instruction.Mnemonic = I_CMPS;
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_CMPSB;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = DSReg;
    }

    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.SegmentReg = ESReg;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    
    FillFlags(pMyDisasm, EFLAGS_CMPS);

    if ((*pMyDisasm).Prefix.Repeat) {
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
}

/* =======================================
 *      a7h
 * ======================================= */
void __bea_callspec__ cmps_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Argument1.AccessMode = READ;
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        /* if there is a prefix override, mnemonic should be "cmps" */
        (*pMyDisasm).Instruction.Mnemonic = I_CMPS;
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = DSReg;
        if ((*pMyDisasm).Instruction.OperandSize == 64) {
            (*pMyDisasm).Instruction.Mnemonic = I_CMPSQ;
        }
        else if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Instruction.Mnemonic = I_CMPSD;
        }
        else {
            (*pMyDisasm).Instruction.Mnemonic = I_CMPSW;
        }
    }
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.SegmentReg = ESReg;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;

    FillFlags(pMyDisasm, EFLAGS_CMPS);

    if ((*pMyDisasm).Prefix.Repeat) {
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
}

/* =======================================
 *      98h
 * ======================================= */
void __bea_callspec__ cwde_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 64) {
        (*pMyDisasm).Instruction.Mnemonic = I_CDQE;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_CWDE;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_CBW;
        (*pMyDisasm).Argument2.ArgSize = 8;
    }
}

/* =======================================
 *      f8h
 * ======================================= */
void __bea_callspec__ clc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CLC;
    FillFlags(pMyDisasm, EFLAGS_CLC);
}

/* =======================================
 *      f8h
 * ======================================= */
void __bea_callspec__ cld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CLD;
    FillFlags(pMyDisasm, EFLAGS_CLD);
}

/* =======================================
 *     fah
 * ======================================= */
void __bea_callspec__ cli_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CLI;
    FillFlags(pMyDisasm, EFLAGS_CLI);
}

/* =======================================
 *      0fa2h
 * ======================================= */
void __bea_callspec__ cpuid_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_CPUID;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG0+REG1+REG2+REG3;
}

/* =======================================
 *     27h
 * ======================================= */
void __bea_callspec__ daa_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DAA;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DAA);
    }
}

/* =======================================
 *     2fh
 * ======================================= */
void __bea_callspec__ das_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DAS;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DAS);
    }
}

/* =======================================
 *      48h
 * ======================================= */
void __bea_callspec__ dec_eax(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 8;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.OperandSize = 64;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DEC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      49h
 * ======================================= */
void __bea_callspec__ dec_ecx(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 8;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 8;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.OperandSize = 64;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DEC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4ah
 * ======================================= */
void __bea_callspec__ dec_edx(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 8;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 8;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.OperandSize = 64;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DEC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4bh
 * ======================================= */
void __bea_callspec__ dec_ebx(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 8;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 8;
        (*pMyDisasm).Prefix.REX.B_ = 8;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.OperandSize = 64;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DEC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4ch
 * ======================================= */
void __bea_callspec__ dec_esp(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 8;
        (*pMyDisasm).Prefix.REX.R_ = 8;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.OperandSize = 64;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DEC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4dh
 * ======================================= */
void __bea_callspec__ dec_ebp(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 8;
        (*pMyDisasm).Prefix.REX.R_ = 8;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 8;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.OperandSize = 64;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DEC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4eh
 * ======================================= */
void __bea_callspec__ dec_esi(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 8;
        (*pMyDisasm).Prefix.REX.R_ = 8;
        (*pMyDisasm).Prefix.REX.X_ = 8;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.OperandSize = 64;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DEC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      4fh
 * ======================================= */
void __bea_callspec__ dec_edi(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 8;
        (*pMyDisasm).Prefix.REX.R_ = 8;
        (*pMyDisasm).Prefix.REX.X_ = 8;
        (*pMyDisasm).Prefix.REX.B_ = 8;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.OperandSize = 64;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_DEC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_DEC);
    }
}

/* =======================================
 *      0c8h
 * ======================================= */
void __bea_callspec__ enter_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_ENTER;
    if (!Security(3, pMyDisasm)) return;
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_));
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+IMM_IN_TYPE+(*((UInt8*)(UIntPtr) (GV.EIP_+2)));
    GV.EIP_+=3;
}

/* =======================================
 *     0f0eh
 * ======================================= */
void __bea_callspec__ femms_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = AMD_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_FEMMS;
}

/* =======================================
 *     f4h
 * ======================================= */
void __bea_callspec__ hlt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_HLT;
}

/* =======================================
 *     0f08h
 * ======================================= */
void __bea_callspec__ invd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_INVD;
}

/* =======================================
 *      40h
 * ======================================= */
void __bea_callspec__ inc_eax(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      41h
 * ======================================= */
void __bea_callspec__ inc_ecx(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 8;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      42h
 * ======================================= */
void __bea_callspec__ inc_edx(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 8;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      43h
 * ======================================= */
void __bea_callspec__ inc_ebx(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 0;
        (*pMyDisasm).Prefix.REX.X_ = 8;
        (*pMyDisasm).Prefix.REX.B_ = 8;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      44h
 * ======================================= */
void __bea_callspec__ inc_esp(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 8;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      45h
 * ======================================= */
void __bea_callspec__ inc_ebp(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 8;
        (*pMyDisasm).Prefix.REX.X_ = 0;
        (*pMyDisasm).Prefix.REX.B_ = 8;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      46h
 * ======================================= */
void __bea_callspec__ inc_esi(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 8;
        (*pMyDisasm).Prefix.REX.X_ = 8;
        (*pMyDisasm).Prefix.REX.B_ = 0;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}

/* =======================================
 *      47h
 * ======================================= */
void __bea_callspec__ inc_edi(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        (*pMyDisasm).Prefix.REX.W_ = 0;
        (*pMyDisasm).Prefix.REX.R_ = 8;
        (*pMyDisasm).Prefix.REX.X_ = 8;
        (*pMyDisasm).Prefix.REX.B_ = 8;
        (*pMyDisasm).Prefix.REXState = InUsePrefix;
        (*pMyDisasm).Prefix.Number++;
        if (!Security1(pMyDisasm)) return;
        GV.EIP_++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)(GV.EIP_-1));
        (void) opcode_map1[*((UInt8*) (UIntPtr)(GV.EIP_-1))](pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (*pMyDisasm).Instruction.Mnemonic = I_INC;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
        FillFlags(pMyDisasm, EFLAGS_INC);
    }
}
/* =======================================
 *      cfh
 * ======================================= */
void __bea_callspec__ iret_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    if ((*pMyDisasm).Instruction.OperandSize ==64) {
        (*pMyDisasm).Instruction.Mnemonic = I_IRETQ;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_IRETD;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_IRETW;
    }
}

/* =======================================
 *     ech
 * ======================================= */
void __bea_callspec__ in_ALDX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_IN;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 16;
}

/* =======================================
 *     e4h
 * ======================================= */
void __bea_callspec__ in_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_IN;
    ALIb(pMyDisasm);
}

/* =======================================
 *      e5h
 * ======================================= */
void __bea_callspec__ in_eAX_Ib(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_IN;
    if (!Security1(pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_+=1;
}

/* =======================================
 *     6ch
 * ======================================= */
void __bea_callspec__ insb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_INSB;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.SegmentReg = ESReg;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 16;
    FillFlags(pMyDisasm, EFLAGS_INS);

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
}

/* =======================================
 *     6dh
 * ======================================= */
void __bea_callspec__ ins_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.SegmentReg = ESReg;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 16;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_INSD;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = 32;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_INSW;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = 16;
    }

    FillFlags(pMyDisasm, EFLAGS_INS);
    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    }
}

/* =======================================
 *     ceh
 * ======================================= */
void __bea_callspec__ into_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_INTO;
        FillFlags(pMyDisasm, EFLAGS_INTO);
    }
}

/* =======================================
 *      0edh
 * ======================================= */
void __bea_callspec__ in_eAX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_IN;
    if ((*pMyDisasm).Instruction.OperandSize >=32) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
}

/* =======================================
 *      0cdh
 * ======================================= */
void __bea_callspec__ int_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_INT;
    if (!Security1(pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_));
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.AccessMode = READ;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_INT);
}

/* =======================================
 *      0f1h
 * ======================================= */
void __bea_callspec__ int1_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_INT1;
    FillFlags(pMyDisasm, EFLAGS_INT);
}

/* =======================================
 *      0cch
 * ======================================= */
void __bea_callspec__ int3_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_INT3;
    FillFlags(pMyDisasm, EFLAGS_INT);
}

/* =======================================
 *      69h
 * ======================================= */
void __bea_callspec__ imul_GvEvIv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_IMUL;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        GV.ImmediatSize = 32;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+4;
        if (!Security(0, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((Int32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 32;
        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
    else {
        GV.ImmediatSize = 16;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
        if (!Security(2, pMyDisasm)) return;
        (*pMyDisasm).Instruction.Immediat = *((Int16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 16;
        FillFlags(pMyDisasm, EFLAGS_IMUL);
    }
}

/* =======================================
 *      6bh
 * ======================================= */
void __bea_callspec__ imul_GvEvIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_IMUL;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    GV.ImmediatSize = 8;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_+= GV.DECALAGE_EIP+1;
    if (!Security(0, pMyDisasm)) return;
    (*pMyDisasm).Instruction.Immediat = *((Int8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;
    FillFlags(pMyDisasm, EFLAGS_IMUL);
}

/* =======================================
 *      0fafh
 * ======================================= */
void __bea_callspec__ imul_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_IMUL;
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ+WRITE;
    FillFlags(pMyDisasm, EFLAGS_IMUL);
}

/* =======================================
 *      70h
 * ======================================= */
void __bea_callspec__ jo_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_O;
    (*pMyDisasm).Instruction.Mnemonic = I_JO;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccO);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      71h
 * ======================================= */
void __bea_callspec__ jno_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NO;
    (*pMyDisasm).Instruction.Mnemonic = I_JNO;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccNO);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      72h
 * ======================================= */
void __bea_callspec__ jb_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_B;
    (*pMyDisasm).Instruction.Mnemonic = I_JB;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccB);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      73h
 * ======================================= */
void __bea_callspec__ jae_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_AE;
    (*pMyDisasm).Instruction.Mnemonic = I_JAE;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccAE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}
/* =======================================
 *      74h
 * ======================================= */
void __bea_callspec__ je_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Instruction.Mnemonic = I_JE;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      75h
 * ======================================= */
void __bea_callspec__ jne_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Instruction.Mnemonic = I_JNE;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccNE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      76h
 * ======================================= */
void __bea_callspec__ jbe_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_BE;
    (*pMyDisasm).Instruction.Mnemonic = I_JBE;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccBE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      77h
 * ======================================= */
void __bea_callspec__ ja_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_A;
    (*pMyDisasm).Instruction.Mnemonic = I_JA;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccA);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      78h
 * ======================================= */
void __bea_callspec__ js_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_S;
    (*pMyDisasm).Instruction.Mnemonic = I_JS;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccS);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      79h
 * ======================================= */
void __bea_callspec__ jns_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NS;
    (*pMyDisasm).Instruction.Mnemonic = I_JNS;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccNS);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      7ah
 * ======================================= */
void __bea_callspec__ jp_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_P;
    (*pMyDisasm).Instruction.Mnemonic = I_JP;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccP);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      7bh
 * ======================================= */
void __bea_callspec__ jnp_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NP;
    (*pMyDisasm).Instruction.Mnemonic = I_JNP;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccNP);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      7ch
 * ======================================= */
void __bea_callspec__ jl_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_L;
    (*pMyDisasm).Instruction.Mnemonic = I_JL;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccL);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      7dh
 * ======================================= */
void __bea_callspec__ jge_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_GE;
    (*pMyDisasm).Instruction.Mnemonic = I_JGE;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccGE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      7eh
 * ======================================= */
void __bea_callspec__ jle_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_LE;
    (*pMyDisasm).Instruction.Mnemonic = I_JLE;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccLE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      7fh
 * ======================================= */
void __bea_callspec__ jg_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_G;
    (*pMyDisasm).Instruction.Mnemonic = I_JG;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccG);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}


/* =======================================
 *      0f80h
 * ======================================= */
void __bea_callspec__ jo_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_O;
    (*pMyDisasm).Instruction.Mnemonic = I_JO;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccO);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}


/* =======================================
 *      0f81h
 * ======================================= */
void __bea_callspec__ jno_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NO;
    (*pMyDisasm).Instruction.Mnemonic = I_JNO;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccNO);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f82h
 * ======================================= */
void __bea_callspec__ jb_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_B;
    (*pMyDisasm).Instruction.Mnemonic = I_JB;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccB);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f83h
 * ======================================= */
void __bea_callspec__ jae_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_AE;
    (*pMyDisasm).Instruction.Mnemonic = I_JAE;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccAE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f84h
 * ======================================= */
void __bea_callspec__ je_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Instruction.Mnemonic = I_JE;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f85h
 * ======================================= */
void __bea_callspec__ jne_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Instruction.Mnemonic = I_JNE;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccNE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}
/* =======================================
 *      0f86h
 * ======================================= */
void __bea_callspec__ jbe_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_BE;
    (*pMyDisasm).Instruction.Mnemonic = I_JBE;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccBE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}


/* =======================================
 *      0f87h
 * ======================================= */
void __bea_callspec__ ja_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_A;
    (*pMyDisasm).Instruction.Mnemonic = I_JA;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccA);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f88h
 * ======================================= */
void __bea_callspec__ js_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_S;
    (*pMyDisasm).Instruction.Mnemonic = I_JS;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccS);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f89h
 * ======================================= */
void __bea_callspec__ jns_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NS;
    (*pMyDisasm).Instruction.Mnemonic = I_JNS;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccNS);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f8ah
 * ======================================= */
void __bea_callspec__ jp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_P;
    (*pMyDisasm).Instruction.Mnemonic = I_JP;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccP);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f8bh
 * ======================================= */
void __bea_callspec__ jnp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NP;
    (*pMyDisasm).Instruction.Mnemonic = I_JNP;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccNP);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f8ch
 * ======================================= */
void __bea_callspec__ jl_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_L;
    (*pMyDisasm).Instruction.Mnemonic = I_JL;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccL);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f8dh
 * ======================================= */
void __bea_callspec__ jge_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_GE;
    (*pMyDisasm).Instruction.Mnemonic = I_JGE;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccGE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f8eh
 * ======================================= */
void __bea_callspec__ jle_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_LE;
    (*pMyDisasm).Instruction.Mnemonic = I_JLE;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccLE);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0f8fh
 * ======================================= */
void __bea_callspec__ jg_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int64 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_G;
    (*pMyDisasm).Instruction.Mnemonic = I_JG;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+6+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_ccG);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0e3h
 * ======================================= */
void __bea_callspec__ jecxz_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int64 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.ConditionalType = CC_ECXZ;
    if ((*pMyDisasm).Instruction.AddressSize == 64) {
        (*pMyDisasm).Instruction.Mnemonic = I_JRCXZ;
    }
    else if ((*pMyDisasm).Instruction.AddressSize == 32) {
        (*pMyDisasm).Instruction.Mnemonic = I_JECXZ;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_JCXZ;
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security1(pMyDisasm)) return;
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_++;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_++;
    }
    FillFlags(pMyDisasm, EFLAGS_JCXZ);
    if ((*pMyDisasm).Prefix.BranchHintsState == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.BranchHintsState = InUsePrefix;
    }
}

/* =======================================
 *      0e9h
 * ======================================= */
void __bea_callspec__ jmp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Instruction.Mnemonic = I_JMP;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        if (!Security(4, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+5+MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=4;
    }
    else {
        if (!Security(2, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_));
        CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+3+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
    }
    FillFlags(pMyDisasm, EFLAGS_JMP);
}


/* =======================================
 *      0ebh
 * ======================================= */
void __bea_callspec__ jmp_short(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Instruction.Mnemonic = I_JMP;
    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    if ((*pMyDisasm).Instruction.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_JMP);
}


/* =======================================
 *      0eah
 * ======================================= */
void __bea_callspec__ jmp_far(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    UInt64 MyAddress;
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_JMP_FAR;
        (*pMyDisasm).Instruction.BranchType = JmpType;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+FARPTR_;
        (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize+16;
        if ((*pMyDisasm).Instruction.OperandSize == 32) {
            if (!Security(6, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+4));
            (*pMyDisasm).Argument1.SegmentReg = MyNumber;
            MyAddress = MyNumber*16;
            MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            GV.EIP_+=6;
        }
        else {
            if (!Security(4, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+2));
            (*pMyDisasm).Argument1.SegmentReg = MyNumber;
            MyAddress = MyNumber*16;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_));
            (*pMyDisasm).Instruction.Immediat = MyNumber;
            GV.EIP_+=4;
        }
        
        (*pMyDisasm).Instruction.AddrValue = MyAddress + MyNumber;
    }
}

/* =======================================
 *      09fh
 * ======================================= */
void __bea_callspec__ lahf_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_LAHF;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.ArgPosition = HighPosition;
}

/* =======================================
 *      0fb6h
 * ======================================= */
void __bea_callspec__ lar_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_LAR;
    GvEw(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_LAR);
}

/* =======================================
 *      0c5h
 * ======================================= */
void __bea_callspec__ lds_GvM(PDISASM pMyDisasm)
{
    /* if MOD == 11b, invalid instruction */
    /* or VEX Prefix - implemented in next release (AVX) */

    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        (*pMyDisasm).Instruction.Mnemonic = I_LDS;
        GvMptp(pMyDisasm);
    }
}

/* =======================================
 *      0c9h
 * ======================================= */
void __bea_callspec__ leave_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_LEAVE;
    (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG4;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG5;
    (*pMyDisasm).Argument2.ArgSize = 32;
}

/* =======================================
 *      08dh
 * ======================================= */
void __bea_callspec__ lea_GvM(PDISASM pMyDisasm)
{

    /* if MOD == 11b, invalid instruction */
    /* or VEX Prefix - implemented in next release (AVX) */

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_LEA;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    else {
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP;
    }
    (*pMyDisasm).Argument2.AccessMode = 0;
}

/* =======================================
 *      0c4h
 * ======================================= */
void __bea_callspec__ les_GvM(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        (*pMyDisasm).Instruction.Mnemonic = I_LES;
        GvMptp(pMyDisasm);
    }
}

/* =======================================
 *      0ach
 * ======================================= */
void __bea_callspec__ lodsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;    
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        (*pMyDisasm).Instruction.Mnemonic = I_LODS;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_LODSB;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = DSReg;
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Argument2.ArgSize = 8;

    FillFlags(pMyDisasm, EFLAGS_LODS);

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG1;
    }
    else {
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
    }
}

/* =======================================
 *      0adh
 * ======================================= */
void __bea_callspec__ lodsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        (*pMyDisasm).Instruction.Mnemonic = I_LODS;
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 64) {
            (*pMyDisasm).Instruction.Mnemonic = I_LODSQ;
        }
        else if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Instruction.Mnemonic = I_LODSD;
        }
        else {
            (*pMyDisasm).Instruction.Mnemonic = I_LODSW;
        }
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = DSReg;
    }
    
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    FillFlags(pMyDisasm, EFLAGS_LODS);

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG1;
    }
    else {
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
    }
}

/* =======================================
 *      0e2h
 * ======================================= */
void __bea_callspec__ loop_(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = LoopType;
    (*pMyDisasm).Instruction.Mnemonic = I_LOOP;

    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
    }
    else {
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
    }

    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_LOOP);
}

/* =======================================
 *      0e0h
 * ======================================= */
void __bea_callspec__ loopne_(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = LoopType;
    (*pMyDisasm).Instruction.ConditionalType = CC_NE;
    (*pMyDisasm).Instruction.Mnemonic = I_LOOPNE;

    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
    }
    else {
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
    }

    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccNE);
}

/* =======================================
 *      0e1h
 * ======================================= */
void __bea_callspec__ loope_(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = LoopType;
    (*pMyDisasm).Instruction.ConditionalType = CC_E;
    (*pMyDisasm).Instruction.Mnemonic = I_LOOPE;

    if (!Security1(pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_));
    CalculateRelativeAddress(&MyAddress,(Int64) (*pMyDisasm).Prefix.Number+2+MyNumber, pMyDisasm);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Instruction.OperandSize >= 32) {
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
    }
    else {
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
    }

    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
    GV.EIP_++;
    FillFlags(pMyDisasm, EFLAGS_ccE);
}

/* =======================================
 *     0f03h
 * ======================================= */
void __bea_callspec__ lsl_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (*pMyDisasm).Instruction.Mnemonic = I_LSL;
    GvEw(pMyDisasm);
    FillFlags(pMyDisasm, EFLAGS_LSL);
}

/* =======================================
 *     0fb2h
 * ======================================= */
void __bea_callspec__ lss_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (*pMyDisasm).Instruction.Mnemonic = I_LSS;
    GvMptp(pMyDisasm);
}

/* =======================================
 *     0fb4h
 * ======================================= */
void __bea_callspec__ lfs_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (*pMyDisasm).Instruction.Mnemonic = I_LFS;
    GvMptp(pMyDisasm);
}

/* =======================================
 *     0fb5h
 * ======================================= */
void __bea_callspec__ lgs_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (*pMyDisasm).Instruction.Mnemonic = I_LGS;
    GvMptp(pMyDisasm);
}

/* =======================================
 *     0f20h
 * ======================================= */
void __bea_callspec__ mov_RdCd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_== 3) {
        (*pMyDisasm).Instruction.Mnemonic = I_MOV;
        RegCR_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_MOVCRDR);
        GV.EIP_ += GV.DECALAGE_EIP;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* =======================================
 *     0f21h
 * ======================================= */
void __bea_callspec__ mov_RdDd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_== 3) {
        (*pMyDisasm).Instruction.Mnemonic = I_MOV;
        RegDR_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_MOVCRDR);
        GV.EIP_ += GV.DECALAGE_EIP;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *     0f22h
 * ======================================= */
void __bea_callspec__ mov_CdRd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_== 3) {
        (*pMyDisasm).Instruction.Mnemonic = I_MOV;
        RegCR_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_MOVCRDR);
        GV.EIP_ += GV.DECALAGE_EIP;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *     0f23h
 * ======================================= */
void __bea_callspec__ mov_DdRd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_== 3) {
        (*pMyDisasm).Instruction.Mnemonic = I_MOV;
        RegDR_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        FillFlags(pMyDisasm, EFLAGS_MOVCRDR);
        GV.EIP_ += GV.DECALAGE_EIP;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      88h
 * ======================================= */
void __bea_callspec__ mov_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    EbGb(pMyDisasm);
}

/* =======================================
 *      89h
 * ======================================= */
void __bea_callspec__ mov_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    EvGv(pMyDisasm);
}

/* =======================================
 *      8ah
 * ======================================= */
void __bea_callspec__ mov_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GbEb(pMyDisasm);
}

/* =======================================
 *      8bh
 * ======================================= */
void __bea_callspec__ mov_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GvEv(pMyDisasm);
}

/* =======================================
 *      0a0h
 * ======================================= */
void __bea_callspec__ mov_ALOb(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE ;
    (*pMyDisasm).Argument2.ArgSize = 8;
    if ((*pMyDisasm).Instruction.AddressSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.AddressSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
}

/* =======================================
 *      0a1h
 * ======================================= */
void __bea_callspec__ mov_eAXOv(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Instruction.AddressSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.AddressSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }

    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
}

/* =======================================
 *      0a2h
 * ======================================= */
void __bea_callspec__ mov_ObAL(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE ;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgSize = 8;
    if ((*pMyDisasm).Instruction.AddressSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.AddressSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
}

/* =======================================
 *      0a3h
 * ======================================= */
void __bea_callspec__ mov_OveAX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Instruction.AddressSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.AddressSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }

    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;

    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE ;
}

/* =======================================
 *      0b0h
 * ======================================= */
void __bea_callspec__ mov_ALIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
}

/* =======================================
 *      0b1h
 * ======================================= */
void __bea_callspec__ mov_CLIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1];
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
}

/* =======================================
 *      0b2h
 * ======================================= */
void __bea_callspec__ mov_DLIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
}

/* =======================================
 *      0b3h
 * ======================================= */
void __bea_callspec__ mov_BLIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3];
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
}

/* =======================================
 *      0b4h
 * ======================================= */
void __bea_callspec__ mov_AHIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
    }
    else if ((*pMyDisasm).Prefix.REXState == 0) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[4];
        (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4];
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
}

/* =======================================
 *      0b5h
 * ======================================= */
void __bea_callspec__ mov_CHIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
    }
    else if ((*pMyDisasm).Prefix.REXState == 0) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[5];
        (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5];
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
}

/* =======================================
 *      0b6h
 * ======================================= */
void __bea_callspec__ mov_DHIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
    }
    else if ((*pMyDisasm).Prefix.REXState == 0) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[6];
        (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6];
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
}

/* =======================================
 *      0b7h
 * ======================================= */
void __bea_callspec__ mov_BHIb(PDISASM pMyDisasm)
{
    Int32 MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_-1));
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
    }
    else if ((*pMyDisasm).Prefix.REXState == 0) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS8BITS[7];
        (*pMyDisasm).Argument1.ArgPosition = HighPosition;
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7];
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
}


/* =======================================
 *      0a4h
 * ======================================= */
void __bea_callspec__ movs_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        /* if there is a prefix override, mnemonic should be "movs" */
        (*pMyDisasm).Instruction.Mnemonic = I_MOVS;
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        (*pMyDisasm).Instruction.Mnemonic = I_MOVSB;
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = DSReg;
    }
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.SegmentReg = ESReg;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    FillFlags(pMyDisasm, EFLAGS_MOVS);

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7+REG1;
    }
    else {
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
    }
}

/* =======================================
 *      0a5h
 * ======================================= */
void __bea_callspec__ movsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if ((*pMyDisasm).Prefix.SegmentState == InUsePrefix) {
        /* if there is a prefix override, mnemonic should be "movs" */
        (*pMyDisasm).Instruction.Mnemonic = I_MOVS;
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = (*pMyDisasm).Prefix.Segment;
    }
    else {
        if ((*pMyDisasm).Instruction.OperandSize == 64) {
            (*pMyDisasm).Instruction.Mnemonic = I_MOVSQ;
        }
        else if ((*pMyDisasm).Instruction.OperandSize == 32) {
            (*pMyDisasm).Instruction.Mnemonic = I_MOVSD;
        }
        else {
            (*pMyDisasm).Instruction.Mnemonic = I_MOVSW;
        }
        (*pMyDisasm).Argument1.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.ArgType = IMPLICIT_ARG+MEMORY_TYPE;
        (*pMyDisasm).Argument2.SegmentReg = DSReg;
    }
    
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.SegmentReg = ESReg;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    FillFlags(pMyDisasm, EFLAGS_MOVS);

    if ((*pMyDisasm).Prefix.Repeat == PrefixRepe) {
        (*pMyDisasm).Prefix.Repeat = PrefixRep;
        (*pMyDisasm).Prefix.RepeatState = InUsePrefix;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7+REG1;
    }
    else {
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
    }
}

/* =======================================
 *      0fb6h
 * ======================================= */
void __bea_callspec__ movzx_GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOVZX;
    GvEb(pMyDisasm);
}


/* =======================================
 *      0fbeh
 * ======================================= */
void __bea_callspec__ movsx_GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOVSX;
    GvEb(pMyDisasm);
}

/* =======================================
 *      0fbfh
 * ======================================= */
void __bea_callspec__ movsx_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOVSX;
    GvEw(pMyDisasm);
}

/* =======================================
 *      0fb7h
 * ======================================= */
void __bea_callspec__ movzx_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOVZX;
    GvEw(pMyDisasm);
}

/* =======================================
 *      0b8h
 * ======================================= */
void __bea_callspec__ mov_EAX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
    }
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
}

/* =======================================
 *      0b9h
 * ======================================= */
void __bea_callspec__ mov_ECX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1];
    }
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
}

/* =======================================
 *      0bah
 * ======================================= */
void __bea_callspec__ mov_EDX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
    }
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
}

/* =======================================
 *      0bbh
 * ======================================= */
void __bea_callspec__ mov_EBX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3];
    }
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
}

/* =======================================
 *      0bch
 * ======================================= */
void __bea_callspec__ mov_ESP(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4];
    }
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
}

/* =======================================
 *      0bdh
 * ======================================= */
void __bea_callspec__ mov_EBP(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5];
    }
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
}

/* =======================================
 *      0beh
 * ======================================= */
void __bea_callspec__ mov_ESI(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6];
    }
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
}

/* =======================================
 *      0bfh
 * ======================================= */
void __bea_callspec__ mov_EDI(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.B_) {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
    }
    else {
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7];
    }
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    (*pMyDisasm).Argument2.ArgSize = (*pMyDisasm).Instruction.OperandSize;
    if ((*pMyDisasm).Instruction.OperandSize == 32) {
        GV.EIP_+=4;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_-4));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else if ((*pMyDisasm).Instruction.OperandSize == 64) {
        GV.EIP_+=8;
        if (!Security(0, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_-8));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
    else {
        GV.EIP_+=2;
        if (!Security(2, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_-2));
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
    }
}
/* =======================================
 *      0c6h-Group 11
 * ======================================= */
void __bea_callspec__ mov_EbIb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOV;
        EbIb(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      0c7h-Group 11
 * ======================================= */
void __bea_callspec__ mov_EvIv(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (*pMyDisasm).Instruction.Mnemonic = I_MOV;
        EvIv(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      08ch
 * ======================================= */
void __bea_callspec__ mov_EwSreg(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.W_) {
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Instruction.OperandSize = 16;
        (*pMyDisasm).Argument1.ArgSize = 16;
    }
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    RegSeg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}

/* =======================================
 *      08eh
 * ======================================= */
void __bea_callspec__ mov_SregEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Instruction.Mnemonic = I_MOV;
    if ((*pMyDisasm).Prefix.REX.W_) {
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else {
        (*pMyDisasm).Instruction.OperandSize = 16;
        (*pMyDisasm).Argument1.ArgSize = 16;
    }
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    RegSeg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.EIP_ += GV.DECALAGE_EIP;
}
