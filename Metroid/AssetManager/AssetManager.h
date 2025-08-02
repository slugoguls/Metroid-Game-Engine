#pragma once

#include <string>
#include <map>
#include <SDL.h>

class AssetManager {
public:
    AssetManager();
    ~AssetManager();

    SDL_Surface* loadSurface(const std::string& assetId, const std::string& path);
    SDL_Surface* getSurface(const std::string& assetId);

    void cleanUp();

private:
    std::map<std::string, SDL_Surface*> surfaces;
};
