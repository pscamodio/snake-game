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

void Snake::update(Game &game, float deltaTime)
{
    // Update snake logic
}

void Snake::render(Game &game)
{
    if (GuiButton((Rectangle){24, 24, 120, 30}, "Stop") > 0)
    {
        game.queueSceneChange(std::make_unique<Menu>());
    }
}
