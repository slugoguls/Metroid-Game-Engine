#pragma once

#include "GameState.h"
#include "../Metroid.h"

class PlayingState : public GameState {
public:
    PlayingState(Engine& engine);
    ~PlayingState();

    void handleEvents() override;
    void update() override;
    void draw() override;

private:
    Engine& engine;
    SDL_Texture* currentTexture = nullptr;
};