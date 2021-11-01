#include "Perso.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Perso::Perso() : Perso("new_perso", V2(200,400), new sf::RectangleShape(sf::Vector2f(40, 100))) {};
Perso::Perso(std::string name, V2 position, sf::RectangleShape * sprite) : 
    Component(position, sprite), m_name(name), jump(false), left(false), right(false)
{
    m_sprite->setFillColor(sf::Color::Red);
}

V2 Perso::get_speed() { return m_speed; }
bool Perso::get_jump() { return jump; }
bool Perso::get_left() { return left; }
bool Perso::get_right() { return right; }

void Perso::set_speed(V2 speed) { m_speed = speed; }
void Perso::set_jump(bool b) { jump = b; }
void Perso::set_left(bool b) { left = b; }
void Perso::set_right(bool b) { right = b; }

void Perso::update_sprite() {
    m_sprite->setPosition(m_pos.get_x(), m_pos.get_y());
}

