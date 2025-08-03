#include "Texture.h"
#include "../Renderer/Renderer.h"
#include <SDL_image.h>
#include <iostream>

Texture::Texture(Renderer& renderer, const std::string& path) : renderer(renderer) {
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }

    // Apply color keying (assuming cyan for transparency)
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

    texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), loadedSurface);
    if (texture == nullptr) {
        std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    }
    else {
        width = loadedSurface->w;
        height = loadedSurface->h;
    }

    SDL_FreeSurface(loadedSurface);
}

Texture::~Texture() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Texture::render(int x, int y, SDL_Rect* clip) {
    renderer.drawTexture(texture, x, y, clip);
}