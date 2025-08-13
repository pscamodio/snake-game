#include "rendering.h"
#include "raylib.h"

void renderGrid(const Grid &grid, const Settings &settings)
{
    const auto [row, cols] = grid;
    const float gameWidth = settings.gameWidth;
    const float gameHeight = settings.gameHeight;
    const int cellSize = settings.cellSize;

    const float startX = (gameWidth - (cols * cellSize)) / 2.F;
    const float startY = (gameHeight - (row * cellSize)) / 2.F;

    for (int i = 0; i <= row; ++i)
    {
        DrawLineEx({startX, startY + i * cellSize},
                   {startX + cols * cellSize, startY + i * cellSize}, 4.F, LIGHTGRAY);
    }
    for (int j = 0; j <= cols; ++j)
    {
        DrawLineEx({startX + j * cellSize, startY},
                   {startX + j * cellSize, startY + row * cellSize}, 4.F, LIGHTGRAY);
    }
}

void renderSnake(const Grid &grid, const Snake &snake, const Settings &settings)
{
    const float gameWidth = settings.gameWidth;
    const float gameHeight = settings.gameHeight;
    const int cellSize = settings.cellSize;

    for (const auto &segment : snake.body)
    {
        const auto posX =
            static_cast<int>((gameWidth - (grid.cols * cellSize)) / 2.F + segment.row * cellSize);
        const auto posY =
            static_cast<int>((gameHeight - (grid.rows * cellSize)) / 2.F + segment.col * cellSize);
        DrawRectangle(posX, posY, cellSize, cellSize, GREEN);
    }
}
