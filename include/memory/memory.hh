#pragma once

#include <cstddef>
#include <vector>

namespace bfc::memory
{
    class Memory
    {
    public:
        Memory(size_t size);

    private:
        std::vector<char> memory_;
    };

} // namespace bfc::memory
