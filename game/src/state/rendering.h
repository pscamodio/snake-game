#pragma once

struct Rendering
{
    // Size of the window, will be used to create the initial window
    // and update if the user resizes it
    int windowWidth = 1280;
    int windowHeight = 720;
    // Scale factor between the game size and the window size
    float scale = 1.0F;
};