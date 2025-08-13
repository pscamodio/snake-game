#pragma once
#include "../utils/cell_index.h"
#include <memory>
#include <vector>

struct Grid
{
    int rows;
    int cols;
};

bool isInsideGrid(const Grid &grid, const CellIndex &cell);
CellIndex getRandomFreePosition(const Grid &grid, const std::vector<CellIndex> &occupiedCells);