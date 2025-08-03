#include "Renderer.h"
#include <iostream>

Renderer::Renderer(const std::string& title, int width, int height)
    : windowTitle(title), screenWidth(width), screenHeight(height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    screenRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (screenRenderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    success = true;
}

Renderer::~Renderer() {
    close();
}

void Renderer::clear() {
    SDL_RenderClear(screenRenderer);
}

void Renderer::present() {
    SDL_RenderPresent(screenRenderer);
}

void Renderer::drawTexture(SDL_Texture* texture) {
    SDL_RenderCopy(screenRenderer, texture, NULL, NULL);
}

void Renderer::close() {
    SDL_DestroyRenderer(screenRenderer);
    SDL_DestroyWindow(window);
    screenRenderer = nullptr;
    window = nullptr;
    IMG_Quit();
    SDL_Quit();
}
