#include "rendering.h"
#include "raylib.h"

void renderGrid(const Grid &grid, const Settings &settings)
{
    const auto [rows, cols, obstacles] = grid;
    const float gameWidth = settings.gameWidth;
    const float gameHeight = settings.gameHeight;
    const float cellSize = static_cast<float>(settings.cellSize);

    const float startX = (gameWidth - (static_cast<float>(cols) * cellSize)) / 2.F;
    const float startY = (gameHeight - (static_cast<float>(rows) * cellSize)) / 2.F;

    for (int i = 0; i <= rows; ++i)
    {
        DrawLineEx({startX, startY + i * cellSize},
                   {startX + cols * cellSize, startY + i * cellSize}, 4.F, LIGHTGRAY);
    }
    for (int j = 0; j <= cols; ++j)
    {
        DrawLineEx({startX + j * cellSize, startY},
                   {startX + j * cellSize, startY + static_cast<float>(rows) * cellSize}, 4.F,
                   LIGHTGRAY);
    }
    for (const auto &obstacle : obstacles)
    {
        const auto posX = static_cast<int>(startX + obstacle.row * cellSize);
        const auto posY = static_cast<int>(startY + obstacle.col * cellSize);
        DrawRectangle(posX, posY, static_cast<int>(cellSize), static_cast<int>(cellSize), DARKGRAY);
    }
}

void renderSnake(const Grid &grid, const Snake &snake, const Settings &settings)
{
    const auto rows = static_cast<float>(grid.rows);
    const auto cols = static_cast<float>(grid.cols);
    const float gameWidth = settings.gameWidth;
    const float gameHeight = settings.gameHeight;
    const float cellSize = static_cast<float>(settings.cellSize);

    for (const auto &segment : snake.body)
    {
        const auto segmentRow = static_cast<float>(segment.row);
        const auto segmentCol = static_cast<float>(segment.col);
        const auto posX =
            static_cast<int>((gameWidth - (cols * cellSize)) / 2.F + segmentRow * cellSize);
        const auto posY =
            static_cast<int>((gameHeight - (rows * cellSize)) / 2.F + segmentCol * cellSize);
        DrawRectangle(posX, posY, settings.cellSize, settings.cellSize, GREEN);
    }
}

void renderFood(const Grid &grid, const CellIndex &food, const Settings &settings)
{
    const auto rows = static_cast<float>(grid.rows);
    const auto cols = static_cast<float>(grid.cols);
    const float gameWidth = settings.gameWidth;
    const float gameHeight = settings.gameHeight;
    const float cellSize = static_cast<float>(settings.cellSize);
    const auto foodRow = static_cast<float>(food.row);
    const auto foodCol = static_cast<float>(food.col);

    const auto posX = static_cast<int>((gameWidth - (cols * cellSize)) / 2.F + foodRow * cellSize);
    const auto posY = static_cast<int>((gameHeight - (rows * cellSize)) / 2.F + foodCol * cellSize);
    DrawRectangle(posX, posY, settings.cellSize, settings.cellSize, RED);
}
