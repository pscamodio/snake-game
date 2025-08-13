#include "grid.h"
#include <algorithm>

bool isInsideGrid(const Grid &grid, const CellIndex &cell)
{
    return cell.row >= 0 && cell.row < grid.rows && cell.col >= 0 && cell.col < grid.cols;
}

auto getRandomFreePosition(const Grid &grid, const std::vector<CellIndex> &occupiedCells)
    -> CellIndex
{
    CellIndex pos;
    do
    {
        pos.row = rand() % grid.rows;
        pos.col = rand() % grid.cols;
    } while (std::find(occupiedCells.begin(), occupiedCells.end(), pos) != occupiedCells.end());
    return pos;
}
