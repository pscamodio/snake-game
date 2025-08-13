#include "menu.h"
#include "../snake/snake.h"
#include "raygui.h"

Menu::Menu()
{
    // Initialize menu
}

Menu::~Menu()
{
    // Cleanup menu
}

void Menu::update([[maybe_unused]] Game &game, [[maybe_unused]] float deltaTime)
{
    // Update menu logic
}

void Menu::render(Game &game)
{
    const auto &settings = game.settings();
    const auto scale = game.runtimeState().scale;
    float buttonWidth = 200.F / scale;
    float buttonHeight = 50.F / scale;
    float centerX = (settings.gameWidth / 2.F) - (buttonWidth / 2.F);
    float centerY = (settings.gameHeight / 2.F) - (buttonHeight / 2.F);

    if (GuiButton({centerX, centerY, buttonWidth, buttonHeight}, "Play Snake") > 0)
    {
        game.queueSceneChange(std::make_unique<Snake>());
    }
}
