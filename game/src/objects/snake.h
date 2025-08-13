#pragma once
#include "../utils/cell_index.h"
#include <vector>

struct Snake
{
    std::vector<CellIndex> body;
    CellIndex direction;
};