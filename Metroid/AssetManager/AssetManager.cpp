#include "AssetManager.h"
#include <iostream>

AssetManager::AssetManager() {}

AssetManager::~AssetManager() {
    cleanUp();
}

SDL_Surface* AssetManager::loadSurface(const std::string& assetId, const std::string& path) {

    SDL_Surface* optimizedSurface = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
    } else {

		optimizedSurface = SDL_ConvertSurface(loadedSurface, loadedSurface->format, 0);
        if (optimizedSurface == nullptr) {
            std::cerr << "Unable to optimize image " << path << "! SDL Error: " << SDL_GetError() << std::endl;
		}
		SDL_FreeSurface(loadedSurface);
    }
    surfaces[assetId] = optimizedSurface;
    return optimizedSurface;
}

SDL_Surface* AssetManager::getSurface(const std::string& assetId) {
    return surfaces.count(assetId) ? surfaces[assetId] : nullptr;
}

void AssetManager::cleanUp() {
    for (auto const& [id, surface] : surfaces) {
        SDL_FreeSurface(surface);
    }
    surfaces.clear();
}
