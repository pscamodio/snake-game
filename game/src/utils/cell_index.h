#pragma once

struct CellIndex
{
    int row = 0;
    int col = 0;
};

CellIndex operator+(const CellIndex &a, const CellIndex &b);
CellIndex &operator+=(CellIndex &a, const CellIndex &b);
bool operator==(const CellIndex &a, const CellIndex &b);