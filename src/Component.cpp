#include "Component.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include <string>

Component::Component(V2 position, sf::RectangleShape* sprite)
{
    m_pos=position; 
    m_sprite=sprite;
    m_sprite->setPosition(position.get_x(), position.get_y());

    std::cout << sprite->getSize().x << std::endl;
    V2 center = position.add(V2(sprite->getSize().x/2, sprite->getSize().y/2));
    this->hitbox = Hitbox(center, V2(sprite->getSize().x, sprite->getSize().y), 1);
}

V2 Component::get_position() { return m_pos; }
Hitbox Component::get_hitbox() { return hitbox; }
sf::RectangleShape Component::get_sprite() { return *m_sprite; }

void Component::set_position(V2 position) { 
    V2 prec = V2(m_pos);
    m_pos = position; 
    m_sprite->setPosition(m_pos.get_x(), m_pos.get_y());
    hitbox.move(m_pos.sub(prec));
}
