#pragma once

#include <SFML/Graphics.hpp>
#include "core/Config.h"

namespace Resource
{
    inline sf::Font Font;
    inline sf::Texture CarTexture;
    inline sf::Texture BackgroundTexture;

    inline bool loadFonts()
    {
        return Font.loadFromFile(Config::FontPath);
    }

    inline bool loadBackGrounds()
    {
        return CarTexture.loadFromFile(Config::CarAssetPath);
    }

    inline bool loadCarAssets()
    {
        return BackgroundTexture.loadFromFile(Config::BackGroundPath);
    }
}