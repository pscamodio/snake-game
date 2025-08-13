#include "snake.h"
#include "raylib.h"

bool updateSnakeDirectionFromKeyboard(Snake &snake)
{
    if (IsKeyPressed(KEY_LEFT) && snake.direction.row != 1)
    {
        snake.direction = {-1, 0};
        return true;
    }
    else if (IsKeyPressed(KEY_RIGHT) && snake.direction.row != -1)
    {
        snake.direction = {1, 0};
        return true;
    }
    else if (IsKeyPressed(KEY_UP) && snake.direction.col != 1)
    {
        snake.direction = {0, -1};
        return true;
    }
    else if (IsKeyPressed(KEY_DOWN) && snake.direction.col != -1)
    {
        snake.direction = {0, 1};
        return true;
    }
    return false;
}

void move(Snake &snake)
{
    const auto size = snake.body.size();
    std::optional<CellIndex> lastSegment = std::nullopt;
    for (size_t i = size; i > 0; --i)
    {
        auto &segment = snake.body[i - 1];
        const auto newSegmentPosition = lastSegment.value_or(segment + snake.direction);
        lastSegment = segment;
        segment = newSegmentPosition;
    }
}

bool willEatSelf(const Snake &snake, const CellIndex &nextMove)
{
    return std::find(snake.body.begin(), snake.body.end(), nextMove) != snake.body.end();
}