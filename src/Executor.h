
#ifndef RISCV_SIM_EXECUTOR_H
#define RISCV_SIM_EXECUTOR_H

#include "Instruction.h"
#include <map>
#include <functional>

class Executor {
public:
    void Execute(InstructionPtr &instr, Word ip) {
        std::map<IType, std::function<void(InstructionPtr &, Word, Executor *)>> instrType;

        instrType = {{IType::Csrr,  [](InstructionPtr &instr, Word ip, Executor *self) {
                        instr->_data = instr->_csrVal;
                        instr->_nextIp = ip + 4;
                    }},

                     {IType::Csrw,  [](InstructionPtr &instr, Word ip, Executor *self) {
                         instr->_data = instr->_src1Val;
                         instr->_nextIp = ip + 4;
                     }},

                     {IType::St,    [](InstructionPtr &instr, Word ip, Executor *self) {
                         instr->_data = instr->_src2Val;
                         instr->_addr = self->performAlu(instr);
                         instr->_nextIp = ip + 4;
                     }},

                     {IType::J,     [](InstructionPtr &instr, Word ip, Executor *self) {
                         instr->_data = ip + 4;
                         if (self->branchCondition(instr))
                             instr->_nextIp = ip + *instr->_imm;
                         else
                             instr->_nextIp = ip + 4;
                     }},

                     {IType::Jr,    [](InstructionPtr &instr, Word ip, Executor *self) {
                         instr->_data = ip + 4;
                         if (self->branchCondition(instr))
                             instr->_nextIp = instr->_src1Val + *instr->_imm;
                         else
                             instr->_nextIp = ip + 4;
                     }},

                     {IType::Auipc, [](InstructionPtr &instr, Word ip, Executor *self) {
                         instr->_data = ip + *instr->_imm;
                         instr->_nextIp = ip + 4;
                     }},

                     {IType::Alu,   [](InstructionPtr &instr, Word ip, Executor *self) {
                         instr->_data = self->performAlu(instr);
                         instr->_nextIp = ip + 4;
                     }},

                     {IType::Br,    [](InstructionPtr &instr, Word ip, Executor *self) {
                         instr->_data = self->performAlu(instr);
                         if (self->branchCondition(instr))
                             instr->_nextIp = ip + *instr->_imm;
                         else
                             instr->_nextIp = ip + 4;
                     }},

                     {IType::Ld,    [](InstructionPtr &instr, Word ip, Executor *self) {
                         instr->_addr = self->performAlu(instr);
                         instr->_nextIp = ip + 4;
                     }}};

        instrType[instr->_type](instr, ip, (Executor *) this);
    }

private:
    // Add helper functions here

    Word performAlu(InstructionPtr &instr) {
        std::map<AluFunc, std::function<Word(InstructionPtr &, Word, Word)>> performAluMap;

        Word a, b;
        if (!instr->_src1)
            return 0;

        a = instr->_src1Val;
        if (!(instr->_imm || instr->_src2))
            return 0;

        b = instr->_imm ? *instr->_imm : instr->_src2Val;

        performAluMap = {{AluFunc::Add,  [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return a + b;
                         }},

                         {AluFunc::Sub,  [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return a - b;
                         }},

                         {AluFunc::And,  [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return a & b;
                         }},

                         {AluFunc::Or,   [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return a | b;

                         }},

                         {AluFunc::Xor,  [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return a ^ b;
                         }},

                         {AluFunc::Slt,  [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return (int) a < (int) b;
                         }},

                         {AluFunc::Sltu, [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return  a < b;
                         }},

                         {AluFunc::Sll,  [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return a << (b % 32);
                         }},

                         {AluFunc::Srl,  [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return a >> (b % 32);
                         }},

                         {AluFunc::Sra,  [](InstructionPtr &instr, Word a, Word b) -> Word {
                             return Word((int) a >> (b % 32));
                         }}};
        return performAluMap[instr->_aluFunc](instr, a, b);
    }

    bool branchCondition(InstructionPtr &instr) {
        std::map<BrFunc, std::function<bool(InstructionPtr &, Word, Word)>> branchConditionMap;

        Word a, b;

        a = instr->_src1Val;
        b = instr->_src2Val;

        branchConditionMap = {{BrFunc::Eq,  [](InstructionPtr &instr, Word a, Word b) -> bool {
                                  return a == b;
                              }},

                              {BrFunc::Neq, [](InstructionPtr &instr, Word a, Word b) -> bool {
                                  return a != b;
                              }},

                              {BrFunc::Lt,  [](InstructionPtr &instr, Word a, Word b) -> bool {
                                  return (int) a < (int) b;
                              }},

                              {BrFunc::Ltu, [](InstructionPtr &instr, Word a, Word b) -> bool {
                                  return a < b;
                              }},

                              {BrFunc::Ge,  [](InstructionPtr &instr, Word a, Word b) -> bool {
                                  return (int) a >= (int) b;
                              }},

                              {BrFunc::Geu, [](InstructionPtr &instr, Word a, Word b) -> bool {
                                  return a >= b;
                              }},

                              {BrFunc::AT,  [](InstructionPtr &instr, Word a, Word b) -> bool {
                                  return true;
                              }},

                              {BrFunc::NT,  [](InstructionPtr &instr, Word a, Word b) -> bool {
                                  return false;
                              }}};

        return branchConditionMap[instr->_brFunc](instr, a, b);
    }
};

#endif // RISCV_SIM_EXECUTOR_H