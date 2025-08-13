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
    float buttonWidth = 200.F;
    float buttonHeight = 50.F;
    float screenWidth = static_cast<float>(settings.screenWidth);
    float screenHeight = static_cast<float>(settings.screenHeight);
    float centerX = (screenWidth / 2.F) - (buttonWidth / 2.F);
    float centerY = (screenHeight / 2.F) - (buttonHeight / 2.F);

    if (GuiButton({centerX, centerY, buttonWidth, buttonHeight}, "Play Snake") > 0)
    {
        game.queueSceneChange(std::make_unique<Snake>());
    }
}
