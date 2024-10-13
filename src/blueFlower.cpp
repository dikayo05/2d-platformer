#include "../include/BlueFlower.hpp"
#include <string>

BlueFlower::BlueFlower(sf::Vector2f position)
{
    // BlueFlower
    for (int8_t i = 0; i < m_texture.size(); i++)
    {
        m_texture[i].loadFromFile("../assets/environment/plants/BlueFlower1/" + std::to_string(i) + ".png");
    }

    this->setScale(m_scaleX, m_scaleY);
    this->setOrigin(m_pixelSizeX / 2, m_pixelSizeY / 2);
    this->setPosition(position);
}

BlueFlower::~BlueFlower()
{
}

void BlueFlower::update()
{
    // animation
    if (m_textureIndex < m_animationDelay)
    {
        m_textureIndex++;
    }
    else
    {
        m_animationCount < (m_texture.size() - 1) ? m_animationCount++ : m_animationCount = 0;
        this->setTexture(m_texture[m_animationCount]);
        m_textureIndex = 0;
    }
}