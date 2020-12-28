#include "doctest.h"

#include "../src/Decoder.h"
#include "../src/Executor.h"

Word ip = 0;
Word src1Val  = 8;
Word src2Val  = 3;
Word csrVal  = 33;
Executor exe;
Decoder d;

TEST_SUITE ( "Executor" ) {
    TEST_CASE ("ADD") {
        Word data;
        data = 0b00000000101010001000100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
                CHECK (instr->_data == src1Val + src2Val);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SUB") {
        Word data;
        data = 0b01000000101010001000100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val - src2Val;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("AND") {
        Word data;
        data = 0b00000000101010001111100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val & src2Val;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("OR") {
        Word data;
        data = 0b00000000101010001110100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val | src2Val;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("XOR") {
        Word data;
        data = 0b00000000101010001100100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val ^ src2Val;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SLT") {
        Word data;
        data = 0b00000000101010001010100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = (int) src1Val < (int) src2Val;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SLTU") {
        Word data;
        data = 0b00000000101010001011100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val < src2Val;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SLL") {
        Word data;
        data = 0b00000000101010001001100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val << (src2Val % 32);
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SRL") {
        Word data;
        data = 0b00000000101010001101100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val >> (src2Val % 32);
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SRA") {
        Word data;
        data = 0b01000000101010001101100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);

        Word temp = (int) src1Val >> (src2Val % 32);
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }
    TEST_CASE ("SRA") {
        Word data;
        data = 0b01000000101010001101100000110011;

        auto instr = d.Decode(data);
        instr->_src2Val = src2Val;
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);

        Word temp = (int) src1Val >> (src2Val % 32);
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("ADDI") {
        Word data;
        data = 0b01011011011001101000010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
                CHECK (instr->_data == src1Val + loadedWord);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("ANDI") {
        Word data;
        data = 0b01011011011001101111010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val & loadedWord;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("ORI") {
        Word data;
        data = 0b01011011011001101110010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val | loadedWord;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("XORI") {
        Word data;
        data = 0b01011011011001101100010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val ^ loadedWord;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SLTI") {
        Word data;
        data = 0b01011011011001101010010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = (int) src1Val < (int) loadedWord;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SLTUI") {
        Word data;
        data = 0b01011011011001101011010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val < loadedWord;
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SLLI") {
        Word data;
        data = 0b00000000101101101001010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        loadedWord >>=7;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val << (loadedWord % 32);
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SRLI") {
        Word data;
        data = 0b00000000101101101101010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        loadedWord >>=7;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val >> (loadedWord % 32);
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("SRAI") {
        Word data;
        data = 0b01000000101101101101010100010011;

        Word loadedWord;
        loadedWord = 0b010110110110;
        loadedWord >>=7;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
        Word temp = src1Val >> (int) src1Val >> (loadedWord % 32);
                CHECK (instr->_data == temp);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("LW") {

        Word data;
        data = 0b01011011011001101010010100000011;
        Word loadedWord;
        loadedWord = 0b010110110110;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
                CHECK (instr->_addr == src1Val + loadedWord);
                CHECK (instr->_nextIp == ip + 4);

    }

    TEST_CASE ("SW") {
        Word data;
        data = 0b01011010101010001010101100100011;
        Word loadedWord;
        loadedWord = 0b010110110110;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
                CHECK (instr->_addr == src1Val + loadedWord);
                CHECK (instr->_nextIp == ip + 4);
    }

    TEST_CASE ("BEQ") {
        Word data;
        data = 0b00000000101010001000100001100011;
        Word loadedWord;
        loadedWord = 0b0000000010000;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        instr->_src2Val = src2Val;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp == ((src1Val == src2Val)? ip + loadedWord  : ip + 4));
    }

    TEST_CASE ("BNE") {
        Word data;
        data = 0b00000000101010001001100001100011;
        Word loadedWord;
        loadedWord = 0b0000000010000;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        instr->_src2Val = src2Val;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp == ((src1Val != src2Val)? ip + loadedWord  : ip + 4));
    }

    TEST_CASE ("BLT") {
        Word data;
        data = 0b00000000101010001100100001100011;
        Word loadedWord;
        loadedWord = 0b0000000010000;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        instr->_src2Val = src2Val;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp == (((int)src1Val < (int)src2Val)? ip + loadedWord  : ip + 4));
    }

    TEST_CASE ("BGE") {
        Word data;
        data = 0b00000000101010001101100001100011;
        Word loadedWord;
        loadedWord = 0b0000000010000;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        instr->_src2Val = src2Val;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp == (((int)src1Val >= (int)src2Val)? ip + loadedWord   : ip + 4));
    }

    TEST_CASE ("BLTU") {
        Word data;
        data = 0b00000000101010001110100001100011;
        Word loadedWord;
        loadedWord = 0b0000000010000;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        instr->_src2Val = src2Val;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp == ((src1Val < src2Val)? ip + loadedWord  : ip + 4));
    }

    TEST_CASE ("BGEU") {
        Word data;
        data = 0b00000000101010001111100001100011;
        Word loadedWord;
        loadedWord = 0b0000000010000;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        instr->_src2Val = src2Val;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp == ((src1Val >= src2Val)? ip + loadedWord : ip + 4));
    }

    TEST_CASE ("LUI") {
        Word data;
        data = 0b00000000000000011011010100110111;
        Word loadedWord;
        loadedWord = 0b00000000000000011011;
        loadedWord <<=12;
        auto instr = d.Decode(data);
        exe.Execute(instr, ip);
                CHECK (instr->_data ==loadedWord);
                CHECK (instr->_nextIp == ip + 4);

    }
    TEST_CASE ("AUIPC") {
        Word data;
        data = 0b00000000000000011011010100010111;
        Word loadedWord;
        loadedWord = 0b00000000000000011011;
        loadedWord <<=12;
        auto instr = d.Decode(data);
        exe.Execute(instr, ip);
                CHECK (instr->_data ==ip + loadedWord);
                CHECK (instr->_nextIp == ip + 4);


    }
    TEST_CASE ("JAL") {
        Word data;
        data = 0b00000011011000000000010101101111;
        Word loadedWord;
        loadedWord = 0b000000000000000110110;
        auto instr = d.Decode(data);
        exe.Execute(instr, ip);
                CHECK (instr->_data ==ip +4 );
    }
    TEST_CASE ("JAL") {
        Word data;
        data = 0b00000000100010001000010101100111;
        Word loadedWord;
        loadedWord = 0b000000001000;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp ==src1Val + loadedWord);
                CHECK (instr->_data ==ip +4 );
    }

    TEST_CASE ("CSRR") {
        Word data;
        data = 0b11110001010000000010010101110011;
        auto instr = d.Decode(data);
        instr->_csrVal = csrVal;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp == ip + 4);
                CHECK (instr->_data ==csrVal);
    }

    TEST_CASE ("CSRW") {
        Word data;
        data = 0b11000000001001011001000001110011;
        auto instr = d.Decode(data);
        instr->_src1Val = src1Val;
        exe.Execute(instr, ip);
                CHECK (instr->_nextIp == ip + 4);
                CHECK (instr->_data ==src1Val);
    }



}