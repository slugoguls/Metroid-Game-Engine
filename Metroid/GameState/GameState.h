#pragma once

#include <functional>

class Renderer;
class AssetManager;
class InputManager;

class GameState {
public:
    virtual ~GameState() = default;

    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

protected:
    GameState(Renderer& renderer, AssetManager& assetManager, InputManager& inputManager, std::function<void()> quitCallback);

    Renderer& renderer;
    AssetManager& assetManager;
    InputManager& inputManager;
    std::function<void()> quitCallback;
};