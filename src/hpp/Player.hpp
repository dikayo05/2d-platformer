#pragma once
#include <SFML\Graphics.hpp>

class Player : public sf::Sprite
{
private:
    float m_pixelSizeX = 512.f,
          m_pixelSizeY = 512.f,
          m_scaleX = 0.3f,
          m_scaleY = 0.3f,
          m_moveSpeed = 210.f,
          m_jumpSpeed = 1000.f,
          m_jumpHeight = 150.f;

    uint8_t m_animationCount = 0,
            m_animationDelay = 17,
            m_textureIndex = 0;

    bool m_isJumping = false;

    sf::Vector2f m_currentPos;
    sf::Texture m_texture[20];
    // sf::Vector2f playerPixelSize;

public:
    Player(sf::Vector2f position);
    ~Player();

    sf::Vector2f getCurrentPos();
    void update(float gravity, float deltaTime);
    void controller(sf::Event event);
};
