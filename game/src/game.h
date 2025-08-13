#pragma once

#include "raylib.h"
#include "settings.h"
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
    const RuntimeState &runtimeState() const;

  private:
    void changeSceneIfNeeded();
    void updateGameState();
    void updateScene();
    void renderToWindow();

    // Add private member variables and functions here
    Settings m_settings = {};
    RuntimeState m_runtimeState = {};
    Font m_defaultFont;
    std::unique_ptr<Scene> m_currentScene;

    std::unique_ptr<Scene> m_nextScene;

    std::unique_ptr<Resource<RenderTexture2D>> m_gameRenderTarget;
};
