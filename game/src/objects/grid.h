#pragma once
#include "../utils/cell_index.h"
#include <memory>
#include <vector>

struct Grid
{
    int rows;
    int cols;
    std::vector<CellIndex> obstacles;
};

bool isInsideGrid(const Grid &grid, const CellIndex &cell);
bool isObstacle(const Grid &grid, const CellIndex &cell);
bool isValidMove(const Grid &grid, const CellIndex &cell);
CellIndex getRandomFreePosition(const Grid &grid, const std::vector<CellIndex> &occupiedCells);