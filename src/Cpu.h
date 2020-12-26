
#ifndef RISCV_SIM_CPU_H
#define RISCV_SIM_CPU_H

#include "Memory.h"
#include "Decoder.h"
#include "RegisterFile.h"
#include "CsrFile.h"
#include "Executor.h"

class Cpu
{
public:
    Cpu(Memory& mem)
            : _mem(mem)
    {

    }

    void ProcessInstruction()
    {

        //fprintf(stderr, "Here\n");
        auto data =  _mem.Request(_ip);
        //fprintf(stderr, "%d\n", data);
        auto instruction = _decoder.Decode(data);

        _rf.Read(instruction);
        _csrf.Read(instruction);

        _exe.Execute(instruction, _ip);
        _mem.Request(instruction);

        _rf.Write(instruction);
        _csrf.Write(instruction);

        _ip = instruction->_nextIp;
        _csrf.InstructionExecuted();


        // Add your code here

    }

    void Reset(Word ip)
    {
        _csrf.Reset();
        _ip = ip;
    }

    std::optional<CpuToHostData> GetMessage()
    {
        return _csrf.GetMessage();
    }

private:
    Reg32 _ip;
    Decoder _decoder;
    RegisterFile _rf;
    CsrFile _csrf;
    Executor _exe;
    Memory& _mem;
};


#endif //RISCV_SIM_CPU_H