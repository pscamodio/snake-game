#pragma once

struct CellIndex
{
    int row = 0;
    int col = 0;
};

const CellIndex INVALID_CELL = {-1, -1};

bool isValid(const CellIndex &cell);

CellIndex operator+(const CellIndex &a, const CellIndex &b);
CellIndex &operator+=(CellIndex &a, const CellIndex &b);
bool operator==(const CellIndex &a, const CellIndex &b);