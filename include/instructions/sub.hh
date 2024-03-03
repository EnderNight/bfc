#pragma once

#include "instructions/instruction.hh"
#include "memory/memory.hh"

namespace bfc::instruction
{
    class Sub : public Instruction
    {
    public:
        void execute(memory::Memory& memory);
    };

} // namespace bfc::instruction
