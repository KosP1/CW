#define  DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "../src/Decoder.h"



TEST_SUITE ( "Decoder" ) {

    TEST_CASE("ADD"){
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        IType opcode;
       // rs2 x10 = 01010
       // rd x16 = 10000
       // rs1 x17  = 10001

        Word data = 0b00000000101010001000100000110011;
        AluFunc dataFunc = AluFunc::Add;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;
        IType dataOpcode =  IType::Alu;
        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("SUB"){
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        IType opcode;
        Word data = 0b01000000101010001000100000110011;
        AluFunc dataFunc = AluFunc::Sub;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;
        IType dataOpcode =  IType::Alu;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("AND"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        Word data = 0b00000000101010001111100000110011;
        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::And;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("OR"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        Word data = 0b00000000101010001110100000110011;
        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::Or;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("XOR"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        Word data = 0b00000000101010001100100000110011;
        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::Xor;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("SLT"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        Word data = 0b00000000101010001010100000110011;
        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::Slt;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("SLTU"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        Word data = 0b00000000101010001011100000110011;
        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::Sltu;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("SLL"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        Word data = 0b00000000101010001001100000110011;
        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::Sll;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("SRL"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        Word data = 0b00000000101010001101100000110011;
        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::Srl;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("SRA"){
        IType opcode;
        AluFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint16_t rd;
        Word data = 0b01000000101010001101100000110011;
        IType dataOpcode =  IType::Alu;
        AluFunc dataFunc = AluFunc::Sra;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint16_t dataRd = 0b10000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        func = instr->_aluFunc;
        rs1 = *instr->_src1;
        rs2 = *instr->_src2;
        rd = *instr->_dst;
                CHECK(dataOpcode == opcode );
                CHECK(dataFunc == func);
                CHECK(dataRs1 == rs1);
                CHECK(dataRs2 == rs2);
                CHECK(dataRd == rd );
    }

    TEST_CASE("ADDI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b01011011011001101000010100010011;

        IType dataOpcode =  IType::Alu;
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

    TEST_CASE("ANDI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b01011011011001101111010100010011;

        IType dataOpcode =  IType::Alu;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::And;
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

    TEST_CASE("ORI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b01011011011001101110010100010011;

        IType dataOpcode =  IType::Alu;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::Or;
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

    TEST_CASE("XORI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b01011011011001101100010100010011;

        IType dataOpcode =  IType::Alu;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::Xor;
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


    TEST_CASE("SLTI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b01011011011001101010010100010011;

        IType dataOpcode =  IType::Alu;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::Slt;
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

    TEST_CASE("SLTUI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b01011011011001101011010100010011;

        IType dataOpcode =  IType::Alu;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::Sltu;
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

    TEST_CASE("SLLI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b00000000101101101001010100010011;

        IType dataOpcode =  IType::Alu;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::Sll;
        uint16_t dataRs = 0b01101;
        uint32_t dataIimm = 0b010110110110;
        dataIimm >>=7;

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

    TEST_CASE("SRLI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b00000000101101101101010100010011;

        IType dataOpcode =  IType::Alu;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::Srl;
        uint16_t dataRs = 0b01101;
        uint32_t dataIimm = 0b010110110110;
        dataIimm >>=7;

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

    TEST_CASE("SRAI"){
        IType opcode;
        uint16_t rd;
        AluFunc func;
        uint16_t rs;
        uint32_t imm;

        Word data = 0b01000000101101101101010100010011;

        IType dataOpcode =  IType::Alu;
        uint16_t dataRd = 0b01010;
        AluFunc dataFunc = AluFunc::Sra;
        uint16_t dataRs = 0b01101;
        uint32_t dataIimm = 0b010110110110;
        dataIimm >>=7;

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
        Word data = 0b00000000101010001000100001100011;
        //0 000000 01010 10001 000 1000 0 1100011

        IType dataOpcode =  IType::Br;
        BrFunc dataFunc = BrFunc::Eq;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint32_t dataIimm = 0b0000000010000;
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

    TEST_CASE("BNE"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint32_t imm;
        Word data = 0b00000000101010001001100001100011;

        IType dataOpcode =  IType::Br;
        BrFunc dataFunc = BrFunc::Neq;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint32_t dataIimm = 0b0000000010000;

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

    TEST_CASE("BLT"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint32_t imm;
        Word data = 0b00000000101010001100100001100011;
        IType dataOpcode =  IType::Br;
        BrFunc dataFunc = BrFunc::Lt;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint32_t dataIimm = 0b0000000010000;

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

    TEST_CASE("BGE"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint32_t imm;
        Word data = 0b00000000101010001101100001100011;

        IType dataOpcode =  IType::Br;
        BrFunc dataFunc = BrFunc::Ge;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint32_t dataIimm = 0b0000000010000;

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

    TEST_CASE("BLTU"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint32_t imm;
        Word data = 0b00000000101010001110100001100011;

        IType dataOpcode =  IType::Br;
        BrFunc dataFunc = BrFunc::Ltu;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint32_t dataIimm = 0b0000000010000;

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

    TEST_CASE("BGEU"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rs2;
        uint32_t imm;
        Word data = 0b00000000101010001111100001100011;

        IType dataOpcode =  IType::Br;
        BrFunc dataFunc = BrFunc::Geu;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRs2 = 0b01010;
        uint32_t dataIimm = 0b0000000010000;

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

    TEST_CASE("AUIPC"){
        IType opcode;
        AluFunc func;
        uint16_t rd;
        uint32_t imm;

        Word data = 0b00000000000000011011010100010111;

        IType dataOpcode =  IType::Auipc;
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

    TEST_CASE("JALR"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rd;
        uint32_t imm;

        Word data = 0b00000000100010001000010101100111;

        IType dataOpcode =  IType::Jr;
        BrFunc dataFunc = BrFunc::AT;
        uint16_t dataRs1 = 0b10001;
        uint16_t dataRd = 0b01010;
        uint32_t dataIimm = 0b000000001000;

        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        rs1 = *instr->_src1;
        rd = *instr->_dst;
        func = instr->_brFunc;
        imm = *instr->_imm;
                CHECK(dataOpcode == opcode );
                CHECK(dataRs1 == rs1 );
                CHECK(dataRd == rd );
                CHECK(dataFunc == func);
                CHECK(dataIimm == imm);
    }

    TEST_CASE("CSRR"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rd;
        CsrIdx csrr;

        Word data = 0b11110001010000000010010101110011;

        IType dataOpcode =  IType::Csrr;
        uint16_t dataRs1 = 0b00000;
        uint16_t dataRd = 0b01010;
        CsrIdx dataCsrr = static_cast<CsrIdx>(0b111100010100);
        // 111100010100 00000 010 01010 1110011
        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        rs1 = *instr->_src1;
        rd = *instr->_dst;
        func = instr->_brFunc;
        csrr = *instr->_csr;
                CHECK(dataOpcode == opcode );
                CHECK(dataRs1 == rs1 );
                CHECK(dataRd == rd );
                CHECK(dataCsrr == csrr);
    }
    
    TEST_CASE("CSRW"){
        IType opcode;
        BrFunc func;
        uint16_t rs1;
        uint16_t rd;
        CsrIdx csrw;

        Word data = 0b11000000001001011001000001110011;

        IType dataOpcode =  IType::Csrw;
        uint16_t dataRs1 = 0b01011;
        uint16_t dataRd = 0b00000;
        CsrIdx dataCsrw = static_cast<CsrIdx>(0b110000000010);
        Decoder d;
        auto instr = d.Decode(data);
        opcode = instr->_type;
        rs1 = *instr->_src1;
        rd = *instr->_dst;
        func = instr->_brFunc;
        csrw = *instr->_csr;
                CHECK(dataOpcode == opcode );
                CHECK(dataRs1 == rs1 );
                CHECK(dataRd == rd );
                CHECK(dataCsrw == csrw);
    }
}
