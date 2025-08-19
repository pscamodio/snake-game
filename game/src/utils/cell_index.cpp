#include "cell_index.h"

bool isValid(const CellIndex &cell)
{
    return cell.row >= 0 && cell.col >= 0;
}

CellIndex operator+(const CellIndex &a, const CellIndex &b)
{
    return {a.row + b.row, a.col + b.col};
}

CellIndex &operator+=(CellIndex &a, const CellIndex &b)
{
    a.row += b.row;
    a.col += b.col;
    return a;
}

bool operator==(const CellIndex &a, const CellIndex &b)
{
    return a.row == b.row && a.col == b.col;
}
