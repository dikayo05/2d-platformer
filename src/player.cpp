#include "../include/Player.hpp"
#include <string>

Player::Player(sf::Vector2f position)
{
    // player
    for (int8_t i = 0; i < m_textureIdle.size(); i++)
    {
        m_textureIdle[i].loadFromFile("../assets/player/BlueWizard/Idle/" + std::to_string(i) + ".png", sf::IntRect(178.5f, 116, m_pixelSizeX, m_pixelSizeY));
        m_textureWalk[i].loadFromFile("../assets/player/BlueWizard/Walk/" + std::to_string(i) + ".png", sf::IntRect(178.5f, 116, m_pixelSizeX, m_pixelSizeY));
    }
    for (int8_t i = 0; i < m_textureJump.size(); i++)
    {
        m_textureJump[i].loadFromFile("../assets/player/BlueWizard/Jump/" + std::to_string(i) + ".png");
    }

    this->setScale(m_scaleX, m_scaleY);
    this->setOrigin(m_pixelSizeX / 2, m_pixelSizeY / 2);
    this->setPosition(position);
}

Player::~Player()
{
}

sf::Vector2f Player::getCurrentPos() { return m_currentPos; }

float Player::getPixelSizeX() { return m_pixelSizeX; }
float Player::getPixelSizeY() { return m_pixelSizeY; }

void Player::controller(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
    {
        this->setScale(-this->m_scaleX, this->m_scaleY);
        m_animationCount = 0;
        m_textureIndex = 0;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
    {
        this->setScale(this->m_scaleX, this->m_scaleY);
        m_animationCount = 0;
        m_textureIndex = 0;
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !this->m_isJumping)
    {
        this->m_currentPos = this->getPosition();
        this->m_isJumping = true;
    }
}

void Player::update(float gravity, float deltaTime, sf::Sprite ground)
{
    // gravity
    if (!this->getGlobalBounds().intersects(ground.getGlobalBounds()))
        this->move(0.f, gravity * deltaTime);

    // movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(-m_moveSpeed * deltaTime, 0.f);

        // animation walk
        if (m_textureIndex < m_animationDelay)
        {
            m_textureIndex++;
        }
        else
        {
            m_animationCount < (m_textureWalk.size() - 1) ? m_animationCount++ : m_animationCount = 0;
            this->setTexture(m_textureWalk[m_animationCount]);
            m_textureIndex = 0;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(m_moveSpeed * deltaTime, 0.f);

        // animation walk
        if (m_textureIndex < m_animationDelay)
        {
            m_textureIndex++;
        }
        else
        {
            m_animationCount < (m_textureWalk.size() - 1) ? m_animationCount++ : m_animationCount = 0;
            this->setTexture(m_textureWalk[m_animationCount]);
            m_textureIndex = 0;
        }
    }
    else
    {
        // animation idle
        if (m_textureIndex < m_animationDelay)
        {
            m_textureIndex++;
        }
        else
        {
            m_animationCount < (m_textureIdle.size() - 1) ? m_animationCount++ : m_animationCount = 0;
            this->setTexture(m_textureIdle[m_animationCount]);
            m_textureIndex = 0;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->move(0.f, -m_jumpSpeed * deltaTime);
    }

    // if (isJumping)
    // {

    // }
}

void Player::animation(std::array<sf::Texture, 20> textureAnimation)
{
    if (m_textureIndex < m_animationDelay)
    {
        m_textureIndex++;
    }
    else
    {
        m_animationCount < (textureAnimation.size() - 1) ? m_animationCount++ : m_animationCount = 0;
        this->setTexture(textureAnimation[m_animationCount]);
        m_textureIndex = 0;
    }
}