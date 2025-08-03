#pragma once

class Engine;

class GameState {
public:
    virtual ~GameState() = default;

    virtual void handleEvents() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

protected:
    GameState(Engine& engine);
    Engine& engine;
};