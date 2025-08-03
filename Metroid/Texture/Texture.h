#pragma once

#include <SDL.h>
#include <string>

class Renderer;

class Texture {
public:
    Texture(Renderer& renderer, const std::string& path);
    ~Texture();

    void render(int x, int y, SDL_Rect* clip = NULL);

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    SDL_Texture* getSDLTexture() const { return texture; }

private:
    Renderer& renderer;
    SDL_Texture* texture = nullptr;
    int width = 0;
    int height = 0;

};