#pragma once

#include <SFML\Graphics.hpp>
#include <array>

class Player : public sf::Sprite
{
private:
    float m_pixelSizeX = 155.f,
          m_pixelSizeY = 280.f,
          m_scaleX = 0.3f,
          m_scaleY = 0.3f,
          m_moveSpeed = 210.f,
          m_jumpSpeed = 1000.f,
          m_jumpHeight = 150.f;

    const uint8_t m_animationDelay = 6;

    uint8_t m_animationCount = 0, // jangan diubah, abaikan aelah
        m_textureIndex = 0;       // jangan diubah, abaikan aelah

    bool m_isJumping = false;

    sf::Vector2f m_currentPos;
    std::array<sf::Texture, 20> m_textureIdle;
    std::array<sf::Texture, 20> m_textureWalk;
    std::array<sf::Texture, 8> m_textureJump;

public:
    Player(sf::Vector2f position);
    ~Player();

    void update(float gravity, float deltaTime, sf::Sprite ground);
    void controller(sf::Event event);
    void animation(std::array<sf::Texture, 20> textureAnimation);

    float getPixelSizeX();
    float getPixelSizeY();
    
    sf::Vector2f getCurrentPos();
};
