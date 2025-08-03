#include "AssetManager.h"
#include <iostream>

AssetManager::AssetManager(SDL_Renderer* renderer) : renderer(renderer) {}

AssetManager::~AssetManager() {
    cleanUp();
}

SDL_Texture* AssetManager::loadTexture(const std::string& assetId, const std::string& path) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            std::cerr << "Unable to create texture from " << path << "! SDL Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }

    textures[assetId] = newTexture;
    return newTexture;
}

SDL_Texture* AssetManager::getTexture(const std::string& assetId) {
    return textures.count(assetId) ? textures[assetId] : nullptr;
}

void AssetManager::cleanUp() {
    for (auto const& [id, texture] : textures) {
        SDL_DestroyTexture(texture);
    }
    textures.clear();
}
