#pragma once

#include "raylib.h"
#include "state/game.h"
#include "state/rendering.h"
#include "state/settings.h"
#include "utils/resource.h"
#include <memory>

class Scene;

class Game
{
  public:
    Game();
    ~Game();
    void run();

    void queueSceneChange(std::unique_ptr<Scene> newScene);

    const Settings &settings() const;
    const Rendering &runtimeState() const;
    const GameState &gameState() const;

    void pushGameState(GameState state);

  private:
    void changeSceneIfNeeded();
    void updateGameState();
    void updateScene();
    void renderToWindow();

    // Add private member variables and functions here
    Settings m_settings = {};
    Rendering m_rendering = {};
    GameState m_gameState = {};
    Font m_defaultFont;
    std::unique_ptr<Scene> m_currentScene;

    std::unique_ptr<Scene> m_nextScene;

    std::unique_ptr<Resource<RenderTexture2D>> m_gameRenderTarget;
};
