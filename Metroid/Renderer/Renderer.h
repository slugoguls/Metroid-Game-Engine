#pragma once

#include <SDL.h>
#include <string>
#include <SDL_image.h>

class Texture;

class Renderer {
public:
    Renderer(const std::string& title, int width, int height);
    ~Renderer();

    void clear();
    void present();
    void drawTexture(SDL_Texture* texture, int x, int y, SDL_Rect* clip = NULL);
    void drawTexture(Texture& texture, int x, int y, SDL_Rect* clip = NULL);

    bool isInitialized() const { return success; }
    SDL_Renderer* getRenderer() const { return screenRenderer; }
    int getScreenWidth() const { return screenWidth; }
    int getScreenHeight() const { return screenHeight; }

private:
    void close();

    bool success = false;
    SDL_Window* window = nullptr;
    SDL_Renderer* screenRenderer = nullptr;
    std::string windowTitle;
    int screenWidth;
    int screenHeight;
};
