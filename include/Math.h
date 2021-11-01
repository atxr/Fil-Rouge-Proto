#ifndef MATH_H // include guard
#define MATH_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>

class V2 {
public:
    V2();
    V2(float, float);

    float get_x();
    float get_y();

    V2 add(V2 a);
    V2 sub(V2 a);
    V2 mul(float a);
    float norm();
    V2 direction();

private:
    float x;
    float y;
};

class Hitbox {
public:
    Hitbox();
    Hitbox(V2 center, V2 size, float delta);

    std::vector<V2> get_points();
    std::vector<V2> get_rectangle();

    void move(V2);


private:
    std::vector<V2> points;
    std::vector<V2> rect;
};

#endif

