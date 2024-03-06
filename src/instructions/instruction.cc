#pragma once

#include "instructions/instruction.hh"

#include "lexer/token.hh"

namespace bfc::instruction
{
    Instruction::Instruction(const lexer::Token& token)
        : token_(token)
    {}

} // namespace bfc::instruction
