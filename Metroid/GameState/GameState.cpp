#include "GameState.h"

GameState::GameState(Renderer& renderer, AssetManager& assetManager, InputManager& inputManager, std::function<void()> quitCallback)
    : renderer(renderer),
      assetManager(assetManager),
      inputManager(inputManager),
      quitCallback(quitCallback) {}