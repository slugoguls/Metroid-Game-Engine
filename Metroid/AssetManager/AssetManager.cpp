#include "AssetManager.h"
#include "../Texture/Texture.h"
#include "../Renderer/Renderer.h"
#include <iostream>

AssetManager::AssetManager(Renderer& renderer) : renderer(renderer) {}

AssetManager::~AssetManager() {
    cleanUp();
}

std::shared_ptr<Texture> AssetManager::loadTexture(const std::string& assetId, const std::string& path) {
    std::shared_ptr<Texture> newTexture = std::make_shared<Texture>(renderer, path);
    textures[assetId] = newTexture;
    return newTexture;
}

std::shared_ptr<Texture> AssetManager::getTexture(const std::string& assetId) {
    return textures.count(assetId) ? textures[assetId] : nullptr;
}

void AssetManager::cleanUp() {
    textures.clear();
}
