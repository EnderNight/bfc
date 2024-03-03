#pragma once

#include "instructions/instruction.hh"
#include "memory/memory.hh"

namespace bfc::instruction
{
    class Right : public Instruction
    {
    public:
        void execute(memory::Memory& memory);
    };

} // namespace bfc::instruction
