#include "Metroid.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Engine::Engine()
    : isRunning(true), renderer("Metroid Engine", SCREEN_WIDTH, SCREEN_HEIGHT) {}

Engine::~Engine() {}

void Engine::loadMedia() {
    assetManager.loadSurface("default", "press.bmp");
    assetManager.loadSurface("up", "up.bmp");
    assetManager.loadSurface("down", "down.bmp");
    assetManager.loadSurface("left", "left.bmp");
    assetManager.loadSurface("right", "right.bmp");

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
            case PlayerAction::UP:
                currentSurface = assetManager.getSurface("up");
                break;
            case PlayerAction::DOWN:
                currentSurface = assetManager.getSurface("down");
                break;
            case PlayerAction::LEFT:
                currentSurface = assetManager.getSurface("left");
                break;
            case PlayerAction::RIGHT:
                currentSurface = assetManager.getSurface("right");
                break;
            case PlayerAction::NONE:
                // If no key is pressed, we can revert to default or do nothing
                // For now, we'll just keep the current surface
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