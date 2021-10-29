#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>
#include "Math.h"

class Component {
public:
    Component(V2, sf::RectangleShape*);

    V2 get_position();
    sf::RectangleShape get_sprite();
    
    void set_position(V2);

protected:
    sf::RectangleShape* m_sprite;
    V2 m_pos;
};

#endif
