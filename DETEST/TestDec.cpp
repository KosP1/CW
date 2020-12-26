#define  DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "../src/Decoder.h"



TEST_SUITE ( "Decoder" ) {

    TEST_CASE("ADD"){
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
       // rs2 x10 = 01010
       // rd x16 = 10000
       // rs1 x17  = 10001

        Word data = 0b00000000101010001000100000110011;
        AluFunc dataFunc = AluFunc::Add;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;

        Decoder d;
        auto instr = d.Decode(data);
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
    }
    TEST_CASE("LW"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b01011011011001101010010100000011;

        IType dataOpcode =  IType::Ld;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::Add;
        uint16_t dataRs = 0b01101;
        uint32_t dataIimm = 0b010110110110;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        rd = *instr->_dst;
        func = instr->_aluFunc;
        rs = *instr->_src1;
        imm = *instr->_imm;
                CHECK(dataOpcode == opcode );
                CHECK(dataRd == rd );
                CHECK(dataFunc == func);
                CHECK(dataIimm == imm);
                CHECK(dataRs == rs);
    }
    TEST_CASE("SW"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint32_t imm;

        Word data = 0b01011010101010001010101100100011;

        IType dataOpcode =  IType::St;
        AluFunc dataFunc = AluFunc::Add;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint32_t dataIimm = 0b010110110110;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        func = instr->_aluFunc;
        imm = *instr->_imm;
                CHECK(dataOpcode == opcode );
                CHECK(dataRs1 == rs1 );
                CHECK(dataRs2 == rs2);
                CHECK(dataIimm == imm);
                CHECK(dataFunc == func);
    }
    TEST_CASE("BEQ"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint32_t imm;

       Word data = 0b00110110101010001000011011100011;

        IType dataOpcode =  IType::Br;
        BrFunc dataFunc = BrFunc::Eq;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint32_t dataIimm = 0b0101101101100;
        //0 011011 01010 10001 000 0110 1 1100011
        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        func = instr->_brFunc;
        imm = *instr->_imm;
                CHECK(dataOpcode == opcode );
                CHECK(dataRs1 == rs1 );
                CHECK(dataRs2 == rs2);
                CHECK(dataIimm == imm);
                CHECK(dataFunc == func);
    }


    TEST_CASE("LUI"){
        IType opcode;
        AluFunc func;
        uint16_t rd;
        uint32_t imm;

        Word data = 0b00000000000000011011010100110111;

        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::Add;
        uint16_t dataRd = 0b01010;
        uint32_t dataIimm = 0b00000000000000011011;
        dataIimm <<=12;
        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        rd = *instr->_dst;
        func = instr->_aluFunc;
        imm = *instr->_imm;
                CHECK(dataOpcode == opcode );
                CHECK(dataRd == rd );
                CHECK(dataFunc == func);
                CHECK(dataIimm == imm);
    }

    TEST_CASE("JAL"){
        IType opcode;
        BrFunc func;
        uint16_t rd;
        uint32_t imm;

        Word data = 0b00000011011000000000010101101111;

        IType dataOpcode =  IType::J;
        BrFunc dataFunc = BrFunc::AT;
        uint16_t dataRd = 0b01010;
        uint32_t dataIimm = 0b000000000000000110110;
        //0 0000011011 0 00000000
        //op 1101111
        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        rd = *instr->_dst;
        func = instr->_brFunc;
        imm = *instr->_imm;
                CHECK(dataOpcode == opcode );
                CHECK(dataRd == rd );
                CHECK(dataFunc == func);
                CHECK(dataIimm == imm);
    }



}
