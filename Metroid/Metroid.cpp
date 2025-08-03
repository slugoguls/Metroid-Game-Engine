#include "Metroid.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Engine::Engine()
    : isRunning(true), renderer("Metroid Engine", SCREEN_WIDTH, SCREEN_HEIGHT) {}

Engine::~Engine() {}

void Engine::loadMedia() {
    assetManager.loadSurface("default", "stretch.bmp");

    currentSurface = assetManager.getSurface("default");
}

void Engine::run() {
    if (!renderer.init()) {
        return;
    }

    loadMedia();

    while (isRunning) {
        PlayerAction action = inputManager.handleInput();

        switch (action) {
            case PlayerAction::QUIT:
                isRunning = false;
                break;
        }

        renderer.drawSurface(currentSurface);
        renderer.present();
    }
}

int main(int argc, char* argv[]) {
    Engine engine;
    engine.run();
    return 0;
}