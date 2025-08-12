#pragma once

#include "settings.h"
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

  private:
    void changeSceneIfNeeded();

    // Add private member variables and functions here
    Settings m_settings = {};
    std::unique_ptr<Scene> m_currentScene;

    std::unique_ptr<Scene> m_nextScene;
};
