#pragma once
#include <SFML\Graphics.hpp>
#include <string>

class BlueFlower : public sf::Sprite
{
private:
    sf::Texture blueFlower1Texture[60];
    // sf::Sprite blueFlower1;
    // sf::Vector2f _pixelSize(768.f, 768.f);
    // sf::Vector2f _scale(0.15f, 0.15f);
    float pixelSizeX = 768.f,
          pixelSizeY = 768.f;
    float scaleX = 0.15f,
          scaleY = 0.15f;
    uint8_t animationCount = 0,
            animationDelay = 2,
            animationSpeedCount = 0;

public:
    BlueFlower(/* args */);
    ~BlueFlower();

    void blueFlower1Animation(uint8_t animationSpeed = 5);
};

BlueFlower::BlueFlower(/* args */)
{
    // blue flower1
    for (int8_t i = 0; i < 60; i++)
    {
        blueFlower1Texture[i].loadFromFile("res\\environment\\plants\\blue flower 1\\" + std::to_string(i) + ".png");
        // return EXIT_FAILURE;
    }

    this->setScale(scaleX, scaleY);
    this->setOrigin(pixelSizeX / 2, pixelSizeY / 2);
    // this->setPosition(WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2);
}

BlueFlower::~BlueFlower()
{
}

void BlueFlower::blueFlower1Animation(uint8_t animationSpeed = 5)
{
    if (animationSpeedCount < animationSpeed)
    {
        animationSpeedCount++;
    }
    else
    {
        animationCount < 59 ? animationCount++ : animationCount = 0;
        this->setTexture(blueFlower1Texture[animationCount]);
        animationSpeedCount = 0;
    }
}
