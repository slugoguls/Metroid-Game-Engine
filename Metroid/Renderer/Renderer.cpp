#include "Renderer.h"
#include <iostream>

Renderer::Renderer(const std::string& title, int width, int height)
    : windowTitle(title), screenWidth(width), screenHeight(height) {}

Renderer::~Renderer() {
    close();
}

bool Renderer::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    screenSurface = SDL_GetWindowSurface(window);
    return true;
}

void Renderer::clear() {
    // Not strictly necessary with surface blitting, but good practice
}

void Renderer::present() {
    SDL_UpdateWindowSurface(window);
}

void Renderer::drawSurface(SDL_Surface* surface) {
    SDL_BlitSurface(surface, NULL, screenSurface, NULL);
}

void Renderer::close() {
    SDL_DestroyWindow(window);
    window = nullptr;
    SDL_Quit();
}
