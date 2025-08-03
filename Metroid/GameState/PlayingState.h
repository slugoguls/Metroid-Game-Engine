#pragma once

#include "GameState.h"
#include <memory>
#include <map>
#include <string>
#include <SDL.h>

class Texture;

class PlayingState : public GameState {
public:
    PlayingState(Renderer& renderer, AssetManager& assetManager, InputManager& inputManager, std::function<void()> quitCallback);
    ~PlayingState();

    void handleEvents() override;
    void update() override;
    void draw() override;

private:
    std::map<std::string, std::shared_ptr<Texture>> textures;
    SDL_Rect gSpriteClips[4];
    int screenWidth;
    int screenHeight;
};