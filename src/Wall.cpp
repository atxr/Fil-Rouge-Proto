#include "Wall.h"

Wall::Wall() : Wall(V2(100,700), new sf::RectangleShape(sf::Vector2f(800, 10))) {};
Wall::Wall(V2 position, sf::RectangleShape * sprite) : 
    Component(position, sprite)
{
    m_sprite->setFillColor(sf::Color::White);
}

