#include "hpp\Player.hpp"
#include <string>

Player::Player(sf::Vector2f position)
{
    // player
    for (int8_t i = 0; i < 20; i++)
    {
        m_texture[i].loadFromFile("res\\player\\blue wizard\\" + std::to_string(i) + ".png");
    }

    this->setScale(m_scaleX, m_scaleY);
    this->setOrigin(m_pixelSizeX / 2, m_pixelSizeY / 2);
    // this->setPosition(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2);
}

Player::~Player()
{
}

sf::Vector2f Player::getCurrentPos() { return m_currentPos; }

void Player::controller(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
        this->setScale(-this->m_scaleX, this->m_scaleY);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
        this->setScale(this->m_scaleX, this->m_scaleY);
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !this->m_isJumping)
    {
        this->m_isJumping = true;
        this->m_currentPos = this->getPosition();
    }
}

void Player::update(float gravity, float deltaTime)
{
    // controller / movement
    if (this->getPosition().y < (300))
        this->move(0.f, gravity * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->move(-m_moveSpeed * deltaTime, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(m_moveSpeed * deltaTime, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->move(0.f, -m_jumpSpeed * deltaTime);
    }

    // if (isJumping)
    // {

    // }

    // animation
    if (m_textureIndex < m_animationDelay)
    {
        m_textureIndex++;
    }
    else
    {
        m_animationCount < 19 ? m_animationCount++ : m_animationCount = 0;
        this->setTexture(m_texture[m_animationCount]);
        m_textureIndex = 0;
    }
}