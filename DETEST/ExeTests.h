
#include "../src/Decoder.h"
#include "../src/Executor.h"
Word ip = 0;
Word src1Val  = 8;
Word src2Val  = 3;
Executor exe;
Decoder d;


bool ExecutorTestADD()
{
    Word data;
    data = 0b00000000101010001000100000110011;

    auto instr = d.Decode(data);
    instr->_src2Val = src2Val;
    instr->_src1Val = src1Val;
    exe.Execute(instr, ip);
    return instr->_data == src1Val+src2Val;
}

bool ExecutorTestLW()
{
    Word data;
    data = 0b01011011011001101010010100000011;
    Word loadedWord = 0b010110110110;
    auto instr = d.Decode(data);
    instr->_src1Val = src1Val;
    exe.Execute(instr, ip);
    return instr->_addr == src1Val + loadedWord;
}

bool ExecutorTestSW()
{
    Word data;
    data = 0b01011010101010001010101100100011;
    Word loadedWord = 0b010110110110;
    auto instr = d.Decode(data);
    instr->_src1Val = src1Val;
    exe.Execute(instr, ip);
    return instr->_addr == src1Val + loadedWord;
}

bool ExecutorTestBEQ()
{
    Word data;
    data = 0b00110110101010001000011011100011;
    Word loadedWord = 0b0101101101100;
    auto instr = d.Decode(data);
    instr->_src1Val = src1Val;
    exe.Execute(instr, ip);
    return instr->_nextIp == ((src1Val == loadedWord)? ip + loadedWord  : ip + 4);
}

bool ExecutorTestLUI()
{
    Word data;
    data = 0b00000000000000011011010100110111;
    Word loadedWord = 0b00000000000000011011;
    loadedWord <<=12;
    auto instr = d.Decode(data);
    exe.Execute(instr, ip);
    return instr->_data ==loadedWord ;
}
bool ExecutorTestJAL()
{
    Word data;
    data = 0b00000011011000000000010101101111;
    Word loadedWord = 0b000000000000000110110;
    auto instr = d.Decode(data);
    exe.Execute(instr, ip);
    return instr->_data ==ip +4 ;
}

