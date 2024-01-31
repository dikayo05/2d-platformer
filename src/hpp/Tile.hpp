#pragma once

#include <SFML\Graphics.hpp>

class Tile : public sf::Sprite
{
private:
    float m_pixelSizeX = 1480.f,
          m_pixelSizeY = 1480.f,
          m_scaleX = 0.3f,
          m_scaleY = 0.3f;

    sf::Texture m_texture;

public:
    Tile(sf::Vector2f position);
    ~Tile();

    float getPixelSizeX();
    float getPixelSizeY();
};
