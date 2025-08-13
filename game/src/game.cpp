#include "game.h"
#include "scenes/menu/menu.h"
#include "scenes/scene.h"
#include <algorithm>
#include <raygui.h>
#include <raylib.h>

Game::Game()
{
    // Initialize the window with settings
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    InitWindow(m_runtimeState.windowWidth, m_runtimeState.windowHeight, m_settings.windowTitle);
    m_currentScene = std::make_unique<Menu>();
    m_gameRenderTarget = std::make_unique<Resource<RenderTexture2D>>(
        LoadRenderTexture(static_cast<int>(m_settings.gameWidth),
                          static_cast<int>(m_settings.gameHeight)),
        UnloadRenderTexture);
    m_defaultFont = GuiGetFont();
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
        this->updateGameState();
        this->updateScene();
        this->renderToWindow();
    }
}

void Game::updateGameState()
{
    const auto windowWidth = GetScreenWidth();
    const auto windowHeight = GetScreenHeight();
    const auto gameWidth = static_cast<int>(m_settings.gameWidth);
    const auto gameHeight = static_cast<int>(m_settings.gameHeight);
    const auto scale = std::min(static_cast<float>(m_runtimeState.windowWidth) / gameWidth,
                                static_cast<float>(m_runtimeState.windowHeight) / gameHeight);

    m_runtimeState.windowWidth = windowWidth;
    m_runtimeState.windowHeight = windowHeight;
    m_runtimeState.scale = scale;

    // Update virtual mouse (clamped mouse value behind game screen)
    Vector2 mouse = GetMousePosition();
    Vector2 virtualMouse = {0, 0};
    virtualMouse.x = std::clamp((mouse.x - (windowWidth - (gameWidth * scale)) * 0.5f) / scale, 0.F,
                                static_cast<float>(gameWidth));
    virtualMouse.y = std::clamp((mouse.y - (windowHeight - (gameHeight * scale)) * 0.5f) / scale,
                                0.F, static_cast<float>(gameHeight));

    // Apply the same transformation as the virtual mouse to the real mouse (i.e. to work with
    // raygui)
    SetMouseOffset(-static_cast<int>(windowWidth - (gameWidth * scale)) / 2,
                   -static_cast<int>(windowHeight - (gameHeight * scale)) / 2);
    SetMouseScale(1 / scale, 1 / scale);

    GuiSetStyle(DEFAULT, TEXT_SIZE, static_cast<int>(20 / scale));
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

    const auto &[windowWidth, windowHeight, scale] = m_runtimeState;

    BeginDrawing();
    ClearBackground(BLACK); // Clear screen background

    // Draw render texture to screen, properly scaled
    DrawTexturePro(m_gameRenderTarget->resource.texture,
                   {0.0f, 0.0f, static_cast<float>(m_gameRenderTarget->resource.texture.width),
                    static_cast<float>(-m_gameRenderTarget->resource.texture.height)},
                   {(windowWidth - (m_settings.gameWidth * scale)) * 0.5f,
                    (windowHeight - (m_settings.gameHeight * scale)) * 0.5f,
                    m_settings.gameWidth * scale, m_settings.gameHeight * scale},
                   {0, 0}, 0.0f, WHITE);
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

auto Game::runtimeState() const -> const RuntimeState &
{
    return m_runtimeState;
}
