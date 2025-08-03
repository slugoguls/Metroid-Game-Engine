#pragma once

#include <SDL.h>
#include <string>
#include <SDL_image.h>

class Renderer {
public:
    Renderer(const std::string& title, int width, int height);
    ~Renderer();

    void clear();
    void present();
    void drawTexture(SDL_Texture* texture);

    bool isInitialized() const { return success; }
    SDL_Renderer* getRenderer() const { return screenRenderer; }

private:
    void close();

    bool success = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* screenRenderer = nullptr;
    std::string windowTitle;
    int screenWidth;
    int screenHeight;
};
