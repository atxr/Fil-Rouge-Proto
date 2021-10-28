// perso.h
#ifndef PERSO_H // include guard
#define PERSO_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Math.h>

class Perso {
public:
    Perso();
    Perso(std::string name);

    V2 get_position();
    V2 get_speed();
    sf::RectangleShape get_sprite();

    void set_position(V2);
    void set_speed(V2);

private:
    std::string m_name;
    sf::RectangleShape* m_sprite;
    V2 m_pos;
    V2 m_speed;
};

#endif /* PERSO_H */

