#include "game.h"
#include "scenes/menu/menu.h"
#include "scenes/scene.h"
#include <raylib.h>

Game::Game()
{
    // Initialize the window with settings
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(m_settings.screenWidth, m_settings.screenHeight, m_settings.windowTitle);
    m_currentScene = std::make_unique<Menu>();
    m_gameRenderTarget = std::make_unique<Resource<RenderTexture2D>>(
        LoadRenderTexture(m_settings.gameWidth, m_settings.gameHeight), UnloadRenderTexture);
}

Game::~Game()
{
    CloseWindow();
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        this->changeSceneIfNeeded();
    }
}

void Game::updateGameState()
{
    m_settings.screenWidth = GetScreenWidth();
    m_settings.screenHeight = GetScreenHeight();
}

void Game::updateScene()
{
    if (!m_gameRenderTarget)
        return;

    BeginTextureMode(m_gameRenderTarget->resource);
    ClearBackground(RAYWHITE);
    m_currentScene->update(*this, GetFrameTime());
    m_currentScene->render(*this);
    EndTextureMode();
}

void Game::renderToWindow()
{
    if (!m_gameRenderTarget)
        return;

    float scale = std::min((float)GetScreenWidth() / m_settings.gameWidth,
                           (float)GetScreenHeight() / m_settings.gameHeight);

    BeginDrawing();
    ClearBackground(BLACK); // Clear screen background

    // Draw render texture to screen, properly scaled
    DrawTexturePro(m_gameRenderTarget->resource.texture,
                   (Rectangle){0.0f, 0.0f, (float)m_gameRenderTarget->resource.texture.width,
                               (float)-m_gameRenderTarget->resource.texture.height},
                   (Rectangle){(GetScreenWidth() - ((float)m_settings.gameWidth * scale)) * 0.5f,
                               (GetScreenHeight() - ((float)m_settings.gameHeight * scale)) * 0.5f,
                               (float)m_settings.gameWidth * scale,
                               (float)m_settings.gameHeight * scale},
                   (Vector2){0, 0}, 0.0f, WHITE);
    EndDrawing();
}

void Game::queueSceneChange(std::unique_ptr<Scene> newScene)
{
    m_nextScene.swap(newScene);
}

void Game::changeSceneIfNeeded()
{
    if (m_nextScene)
    {
        m_currentScene.swap(m_nextScene);
        m_nextScene.reset();
    }
}

auto Game::settings() const -> const Settings &
{
    return m_settings;
}
