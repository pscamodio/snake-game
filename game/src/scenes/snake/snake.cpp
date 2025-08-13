#include "snake.h"
#include "../menu/menu.h"
#include "raygui.h"

Snake::Snake()
{
    // Initialize snake
}

Snake::~Snake()
{
    // Cleanup snake
}

void Snake::update([[maybe_unused]] Game &game, [[maybe_unused]] float deltaTime)
{
    // Update snake logic
}

void Snake::render(Game &game)
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
}
