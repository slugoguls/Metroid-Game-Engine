#pragma once

#include <string>
#include <map>
#include <memory>
#include <SDL.h>
#include <SDL_image.h>

class Renderer;
class Texture;

class AssetManager {
public:
    AssetManager(Renderer& renderer);
    ~AssetManager();

    std::shared_ptr<Texture> loadTexture(const std::string& assetId, const std::string& path);
    std::shared_ptr<Texture> getTexture(const std::string& assetId);

private:
    void cleanUp();
    
    Renderer& renderer;
    std::map<std::string, std::shared_ptr<Texture>> textures;
};
