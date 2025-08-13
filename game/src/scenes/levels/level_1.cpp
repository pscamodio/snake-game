#include "level_1.h"
#include "../../utils/rendering.h"
#include "../menu/menu.h"
#include "raygui.h"

Level1::Level1()
{
    // Initialize level 1
}

Level1::~Level1()
{
    // Cleanup level 1
}

void Level1::update([[maybe_unused]] Game &game, [[maybe_unused]] float deltaTime)
{
    if (!m_alive)
        return;
    const auto hasMoved = updateSnakeDirectionFromKeyboard(m_snake);

    m_timer += deltaTime;
    if (m_timer < m_secondsForCell || hasMoved)
        return;

    m_timer = 0;
    const auto nextCell = m_snake.body.back() + m_snake.direction;
    m_alive = isInsideGrid(m_grid, nextCell) && !willEatSelf(m_snake, nextCell);
    if (m_alive)
    {
        if (nextCell == m_food)
        {
            m_snake.body.push_back(nextCell);
            m_food = getRandomFreePosition(m_grid, m_snake.body);
        }
        else
        {
            move(m_snake);
        }
    }
}

void Level1::render(Game &game)
{
    Rectangle stopButtonRect;
    stopButtonRect.x = 24;
    stopButtonRect.y = 24;
    stopButtonRect.width = 120;
    stopButtonRect.height = 30;

    if (GuiButton(stopButtonRect, "Restart") > 0)
    {
        game.queueSceneChange(std::make_unique<Level1>());
    }

    renderGrid(m_grid, game.settings());
    renderSnake(m_grid, m_snake, game.settings());
    renderFood(m_grid, m_food, game.settings());

    if (!m_alive)
    {
        DrawText("Game Over", 350, 250, 20, RED);
    }
}
