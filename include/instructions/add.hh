#pragma once

#include "instructions/instruction.hh"
#include "memory/memory.hh"

namespace bfc::instruction
{
    class Add : public Instruction
    {
    public:
        void execute(memory::Memory& memory);
    };

} // namespace bfc::instruction
