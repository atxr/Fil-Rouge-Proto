#ifndef WALL_H
#define WALL_H

#include "Component.h"
#include <SFML/Graphics/RectangleShape.hpp>

class Wall: public Component {
public:
    Wall();
    Wall(V2 position, sf::RectangleShape* sprite);
};

#endif

