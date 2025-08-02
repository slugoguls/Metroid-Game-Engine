#pragma once

#include "InputManager/Input.h"
#include "AssetManager/AssetManager.h"
#include "Renderer/Renderer.h"

class Engine {
public:
    Engine();
    ~Engine();

    void run();

private:
    void loadMedia();

    bool isRunning;
    Renderer renderer;
    InputManager inputManager;
    AssetManager assetManager;
    SDL_Surface* currentSurface = nullptr;
};