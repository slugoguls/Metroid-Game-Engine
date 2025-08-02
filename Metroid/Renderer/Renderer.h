#pragma once

#include <SDL.h>
#include <string>

class Renderer {
public:
    Renderer(const std::string& title, int width, int height);
    ~Renderer();

    bool init();
    void clear();
    void present();
    void drawSurface(SDL_Surface* surface);
    void close();

private:
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;
    std::string windowTitle;
    int screenWidth;
    int screenHeight;
};
