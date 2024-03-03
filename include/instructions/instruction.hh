#pragma once

#include "lexer/token.hh"
#include "memory/memory.hh"

namespace bfc::instruction
{
    class Instruction
    {
    public:
        Instruction(const lexer::Token& token);

        virtual ~Instruction();

        virtual void execute(memory::Memory& memory) = 0;

    private:
        lexer::Token token_;
    };

} // namespace bfc::instruction
