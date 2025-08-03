#include "PlayingState.h"
#include "../Texture/Texture.h"
#include "../Renderer/Renderer.h"
#include "../AssetManager/AssetManager.h"
#include "../InputManager/Input.h"

PlayingState::PlayingState(Renderer& renderer, AssetManager& assetManager, InputManager& inputManager, std::function<void()> quitCallback)
    : GameState(renderer, assetManager, inputManager, quitCallback),
      screenWidth(renderer.getScreenWidth()),
      screenHeight(renderer.getScreenHeight()) {
    textures["dots"] = assetManager.loadTexture("dots", "dots.png");

    //Set top left sprite
    gSpriteClips[0].x = 0;
    gSpriteClips[0].y = 0;
    gSpriteClips[0].w = 100;
    gSpriteClips[0].h = 100;

    //Set top right sprite
    gSpriteClips[1].x = 100;
    gSpriteClips[1].y = 0;
    gSpriteClips[1].w = 100;
    gSpriteClips[1].h = 100;

    //Set bottom left sprite
    gSpriteClips[2].x = 0;
    gSpriteClips[2].y = 100;
    gSpriteClips[2].w = 100;
    gSpriteClips[2].h = 100;

    //Set bottom right sprite
    gSpriteClips[3].x = 100;
    gSpriteClips[3].y = 100;
    gSpriteClips[3].w = 100;
    gSpriteClips[3].h = 100;
}

PlayingState::~PlayingState() {}

void PlayingState::handleEvents() {
    PlayerAction action = inputManager.handleInput();

    if (action == PlayerAction::QUIT) {
        quitCallback();
    }
}

void PlayingState::update() {}

void PlayingState::draw() {
    renderer.clear();
    if (textures["dots"]) {
        renderer.drawTexture(*textures["dots"], 0, 0, &gSpriteClips[0]);
        renderer.drawTexture(*textures["dots"], screenWidth - gSpriteClips[1].w, 0, &gSpriteClips[1]);
        renderer.drawTexture(*textures["dots"], 0, screenHeight - gSpriteClips[2].h, &gSpriteClips[2]);
        renderer.drawTexture(*textures["dots"], screenWidth - gSpriteClips[3].w, screenHeight - gSpriteClips[3].h, &gSpriteClips[3]);
    }
    renderer.present();
}