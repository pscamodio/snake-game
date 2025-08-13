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
    if (IsKeyPressed(KEY_LEFT))
    {
        m_snake.direction = {-1, 0};
    }
    else if (IsKeyPressed(KEY_RIGHT))
    {
        m_snake.direction = {1, 0};
    }
    else if (IsKeyPressed(KEY_UP))
    {
        m_snake.direction = {0, -1};
    }
    else if (IsKeyPressed(KEY_DOWN))
    {
        m_snake.direction = {0, 1};
    }

    m_timer += deltaTime;
    if (m_timer >= m_secondsForCell)
    {
        m_snake.body[0].row += m_snake.direction.row;
        m_snake.body[0].col += m_snake.direction.col;
        m_timer = 0;
    }
}

void Level1::render(Game &game)
{
    Rectangle stopButtonRect;
    stopButtonRect.x = 24;
    stopButtonRect.y = 24;
    stopButtonRect.width = 120;
    stopButtonRect.height = 30;

    if (GuiButton(stopButtonRect, "Stop") > 0)
    {
        game.queueSceneChange(std::make_unique<Menu>());
    }

    renderGrid(m_grid, game.settings());
    renderSnake(m_grid, m_snake, game.settings());
}
