#include "GameStateManager.h"

GameStateManager::GameStateManager(Engine& engine) : engine(engine) {}

GameStateManager::~GameStateManager() {
    while (!states.empty()) {
        popState();
    }
}

void GameStateManager::pushState(std::unique_ptr<GameState> state) {
    states.push_back(std::move(state));
}

void GameStateManager::popState() {
    if (!states.empty()) {
        states.pop_back();
    }
}

void GameStateManager::changeState(std::unique_ptr<GameState> state) {
    popState();
    pushState(std::move(state));
}

void GameStateManager::handleEvents() {
    if (!states.empty()) {
        states.back()->handleEvents();
    }
}

void GameStateManager::update() {
    if (!states.empty()) {
        states.back()->update();
    }
}

void GameStateManager::draw() {
    if (!states.empty()) {
        states.back()->draw();
    }
}