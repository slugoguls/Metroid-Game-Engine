#pragma once

#include <SDL.h>

enum class PlayerAction {
    NONE,
    QUIT,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class InputManager {
public:
    PlayerAction handleInput();
};
