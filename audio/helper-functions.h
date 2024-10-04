#pragma once
#include <array>
#include <span>

namespace audio{
    void stream_write(std::span<std::array<int, 10>>& p_Buffer);
};