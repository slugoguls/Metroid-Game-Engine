#pragma once

#include "InputManager/Input.h"
#include "AssetManager/AssetManager.h"
#include "Renderer/Renderer.h"
#include "GameState/GameStateManager.h"

class Engine {
public:
    Engine();
    ~Engine();

    void run();
    void quit();

    Renderer& getRenderer() { return renderer; }
    AssetManager& getAssetManager() { return assetManager; }
    InputManager& getInputManager() { return inputManager; }

private:
    Renderer renderer;
    AssetManager assetManager;
    InputManager inputManager;
    GameStateManager gameStateManager;
    bool isRunning = true;
};