#include "Perso.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Perso::Perso() : Perso("new_perso") {};
Perso::Perso(std::string name) : m_name(name) 
{
    set_position(V2(100, 100));
    m_sprite = new sf::RectangleShape(sf::Vector2f(20, 40));
    m_sprite->setPosition(m_pos.x, m_pos.y);
    m_sprite->setFillColor(sf::Color::Red);
}

V2 Perso::get_position() { return m_pos; }
V2 Perso::get_speed() { return m_speed; }
sf::RectangleShape Perso::get_sprite() { return *m_sprite; }

void Perso::set_position(V2 position) { m_pos = position; }
void Perso::set_speed(V2 speed) { m_speed = speed; }

