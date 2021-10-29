#include "Perso.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Perso::Perso() : Perso("new_perso", V2(200,400), new sf::RectangleShape(sf::Vector2f(40, 100))) {};
Perso::Perso(std::string name, V2 position, sf::RectangleShape * sprite) : 
    Component(position, sprite), m_name(name) 
{
    m_sprite->setFillColor(sf::Color::Red);
}

V2 Perso::get_speed() { return m_speed; }

void Perso::set_speed(V2 speed) { m_speed = speed; }

