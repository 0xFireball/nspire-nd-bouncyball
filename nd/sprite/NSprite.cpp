
#include "NSprite.h"

void NSprite::loadGraphic(NAssetPath asset) {
    // load BMP asset and save to _graphic
    // use asset loader to get full path
    std::string asset_full_path = NAssetLoader::get_full_path(asset);
    SDL_Surface* assetBmp = NAssetLoader::load_bmp_ex(asset_full_path);
    this->_graphic = assetBmp;
}
