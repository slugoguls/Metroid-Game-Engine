#include "Metroid.h"
#include "GameState/PlayingState.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Engine::Engine()
    : renderer("Metroid Engine", SCREEN_WIDTH, SCREEN_HEIGHT),
      assetManager(renderer),
      gameStateManager(*this) {}

Engine::~Engine() {}

void Engine::run() {
    if (!renderer.isInitialized()) {
        return;
    }

    gameStateManager.pushState(std::make_unique<PlayingState>(
        renderer,
        assetManager,
        inputManager,
        [this]() { quit(); }
    ));

    while (isRunning) {
        gameStateManager.handleEvents();
        gameStateManager.update();
        gameStateManager.draw();
    }
}

void Engine::quit() {
    isRunning = false;
}

int main(int argc, char* argv[]) {
    Engine engine;
    engine.run();
    return 0;
}