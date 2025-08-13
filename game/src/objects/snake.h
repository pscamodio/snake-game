#pragma once
#include "../utils/cell_index.h"
#include "grid.h"
#include <vector>

struct Snake
{
    std::vector<CellIndex> body;
    CellIndex direction;
};

bool updateSnakeDirectionFromKeyboard(Snake &snake);
void move(Snake &snake);
bool willEatSelf(const Snake &snake, const CellIndex &nextMove);