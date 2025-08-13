#pragma once

struct Settings
{
    const char *windowTitle = "Snake Game";

    const int minScreenWidth = 800;
    const int minScreenHeight = 600;

    const int cellSize = 50;

    // Size of the game render target, will be scaled to fit the window
    // all the game logic/rendering should refer to this size
    const float gameWidth = 1280.F;
    const float gameHeight = 720.F;
    const int targetFps = 60;
};

struct RuntimeState
{
    // Size of the window, will be used to create the initial window
    // and update if the user resizes it
    int windowWidth = 1280;
    int windowHeight = 720;
    // Scale factor between the game size and the window size
    float scale = 1.0F;
};