#pragma once
#include <SDL.h>

enum class PlayerAction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
    NONE
};

class InputManager {
public:
    PlayerAction handleInput();
};
