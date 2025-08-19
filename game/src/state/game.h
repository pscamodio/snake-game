#pragma once
#include <cstdint>

struct GameState
{
    bool paused = false;
    uint32_t level = 0;
    uint64_t score = 0;
};