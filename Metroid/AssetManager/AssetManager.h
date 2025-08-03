#pragma once

#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

class AssetManager {
public:
    AssetManager(SDL_Renderer* renderer);
    ~AssetManager();

    SDL_Texture* loadTexture(const std::string& assetId, const std::string& path);
    SDL_Texture* getTexture(const std::string& assetId);

private:
    void cleanUp();
    
    SDL_Renderer* renderer;
    std::map<std::string, SDL_Texture*> textures;
};
