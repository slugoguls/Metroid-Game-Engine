#include "Input.h"

PlayerAction InputManager::handleInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            return PlayerAction::QUIT;
        }
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    return PlayerAction::UP;
                case SDLK_DOWN:
                    return PlayerAction::DOWN;
                case SDLK_LEFT:
                    return PlayerAction::LEFT;
                case SDLK_RIGHT:
                    return PlayerAction::RIGHT;
                default:
                    break;
            }
        }
    }
    return PlayerAction::NONE;
}