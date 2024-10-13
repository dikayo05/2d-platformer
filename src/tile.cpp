#include "../include/Tile.hpp"

Tile::Tile(sf::Vector2f position)
{
    m_texture.loadFromFile("../assets/tiles/MossyTileset/Mossy - TileSet.png", sf::IntRect(26, 26, m_pixelSizeX, m_pixelSizeY));

    this->setTexture(m_texture);
    this->setOrigin(m_pixelSizeX / 2, m_pixelSizeY / 2);
    this->setScale(m_scaleX, m_scaleY);
    this->setPosition(position);
}

Tile::~Tile()
{
}

float Tile::getPixelSizeX() { return m_pixelSizeX; }
float Tile::getPixelSizeY() { return m_pixelSizeY; }