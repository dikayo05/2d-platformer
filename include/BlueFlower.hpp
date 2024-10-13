#pragma once

#include <SFML\Graphics.hpp>
#include <array>

class BlueFlower : public sf::Sprite
{
private:
    float m_pixelSizeX = 768.f,
          m_pixelSizeY = 768.f,
          m_scaleX = 0.15f,
          m_scaleY = 0.15f;

    uint8_t m_animationCount = 0,
            m_animationDelay = 8,
            m_textureIndex = 0;

    std::array<sf::Texture, 15> m_texture;

public:
    BlueFlower(sf::Vector2f position);
    ~BlueFlower();

    void update();
};
