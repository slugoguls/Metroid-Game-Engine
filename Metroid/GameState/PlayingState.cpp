#include "PlayingState.h"

PlayingState::PlayingState(Engine& engine)
    : GameState(engine), engine(engine) {
    currentTexture = engine.getAssetManager().loadTexture("default", "texture.png");
}

PlayingState::~PlayingState() {}

void PlayingState::handleEvents() {
    PlayerAction action = engine.getInputManager().handleInput();

    if (action == PlayerAction::QUIT) {
        engine.quit();
    }
}

void PlayingState::update() {}

void PlayingState::draw() {
    engine.getRenderer().clear();
    engine.getRenderer().drawTexture(currentTexture);
    engine.getRenderer().present();
}