#include "Perso.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Perso::Perso() : Perso("perso") {};
Perso::Perso(std::string name) : m_name(name) 
{
    m_sprite = new sf::RectangleShape(sf::Vector2f(20, 40));
    m_sprite->setPosition(200, 500);
    m_sprite->setFillColor(sf::Color::Red);
}

V2 Perso::get_position() { return m_pos; }
V2 Perso::get_speed() { return m_speed; }

void Perso::set_position(V2 position) { m_pos = position; }
void Perso::set_speed(V2 speed) { m_speed = speed; }

