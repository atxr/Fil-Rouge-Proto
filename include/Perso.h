// perso.h
#ifndef PERSO_H // include guard
#define PERSO_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Component.h"

class Perso: public Component {
public:
    Perso();
    Perso(std::string name, V2 position, sf::RectangleShape* sprite);

    V2 get_speed();
    bool get_jump();
    bool get_left();
    bool get_right();
    void set_speed(V2);
    void set_jump(bool);
    void set_left(bool);
    void set_right(bool);

    void update_sprite();

private:
    std::string m_name;
    V2 m_speed;
    bool jump;
    bool right;
    bool left;
};

#endif /* PERSO_H */

