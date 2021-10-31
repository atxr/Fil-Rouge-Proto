#include "Math.h"
#include <vector>

#include <iostream>

V2::V2() : V2(0,0) {}
V2::V2(float a, float b) : x(a), y(b) {}

float V2::get_x() { return x; }
float V2::get_y() { return y; }

V2 V2::add(V2 a) {
    return V2(x + a.get_x(), y + a.get_y());
}

V2 V2::mul(float a) {
    return V2(a*x, a*y);
}

Hitbox::Hitbox() {}
Hitbox::Hitbox(V2 center, V2 size, int n) :
    direction(V2(0, 1))
{
    points = {};

    float x0 = center.get_x();
    float y0 = center.get_y();
    float lx = size.get_x();
    float ly = size.get_y();

    std::cout << lx << " " << ly << std::endl;

    for (float i=0; 4*i<n; i++) {
        points.push_back(
                V2(x0 + (lx/2)*(8*i/n -1), y0 - ly/2));
        points.push_back(
                V2(x0 + (lx/2)*(8*i/n -1), y0 + ly/2));
        points.push_back(
                V2(x0 - (lx/2), y0 + (ly/2)*(8*i/n -1)));
        points.push_back(
                V2(x0 + (lx/2), y0 + (ly/2)*(8*i/n -1)));
    }
    
}

std::vector<V2> Hitbox::get_points() { return points; }

