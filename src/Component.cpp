#include "Component.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>

Component::Component(V2 position, sf::RectangleShape* sprite) :
    m_pos(position), m_sprite(sprite)
{
    m_sprite->setPosition(position.get_x(), position.get_y());
}

V2 Component::get_position() { return m_pos; }
sf::RectangleShape Component::get_sprite() { return *m_sprite; }

void Component::set_position(V2 position) { m_pos = position; }
