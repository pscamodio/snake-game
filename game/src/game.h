#pragma once

#include "settings.h"

class Game
{
  public:
    Game();
    ~Game();
    void run();

  private:
    // Add private member variables and functions here
    Settings m_settings = {};
};
