#pragma once

#include <SFML\Graphics.hpp>

class Camera : public sf::View
{
private:
    /* data */
public:
    Camera(/* args */);
    ~Camera();

    void follow(sf::Sprite target);
};
