#pragma once

#include <vector>
#include <memory>
#include "GameState.h"

class Engine;

class GameStateManager {
public:
    GameStateManager(Engine& engine);
    ~GameStateManager();

    void pushState(std::unique_ptr<GameState> state);
    void popState();
    void changeState(std::unique_ptr<GameState> state);

    void handleEvents();
    void update();
    void draw();

private:
    Engine& engine;
    std::vector<std::unique_ptr<GameState>> states;
};