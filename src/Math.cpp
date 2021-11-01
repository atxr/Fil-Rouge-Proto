#include "Math.h"
#include <vector>
#include <math.h>

#include <iostream>

V2::V2() : V2(0,0) {}
V2::V2(float a, float b) : x(a), y(b) {}

float V2::get_x() { return x; }
float V2::get_y() { return y; }

V2 V2::add(V2 a) { return V2(x + a.get_x(), y + a.get_y()); }
V2 V2::sub(V2 a) { return V2(x - a.get_x(), y - a.get_y()); }
V2 V2::mul(float a) { return V2(a*x, a*y); }

float V2::norm() { return sqrt(x*x + y*y); }
V2 V2::direction() { return norm()==0 ? V2() : mul(1/norm()); }

Hitbox::Hitbox() {}
Hitbox::Hitbox(V2 center, V2 size, float delta)
{
    float x0 = center.get_x();
    float y0 = center.get_y();
    float lx = size.get_x();
    float ly = size.get_y();

    rect = {V2(x0-lx/2, y0-ly/2),
            V2(x0+lx/2, y0-ly/2),
            V2(x0+lx/2, y0+ly/2),
            V2(x0-lx/2, y0+ly/2)};

    points = {};

    for (float i=-lx/2; i<lx/2; i+=delta) {
        points.push_back(V2(x0 + i, y0 - ly/2));
        points.push_back(V2(x0 + i, y0 + ly/2));
    }
    for (float j=-ly/2; j<ly/2; j+=delta) {
        points.push_back(V2(x0 - lx/2, y0 + j));
        points.push_back(V2(x0 + lx/2, y0 + j));
    }

    // Right bottom corner
    points.push_back(V2(x0+lx/2, y0+ly/2));
    
}

std::vector<V2> Hitbox::get_rectangle() { return rect; }
std::vector<V2> Hitbox::get_points() { return points; }

void Hitbox::move(V2 a) {
    for (int i=0; i<rect.size(); i++) {
        rect[i] = rect[i].add(a);
    }
    for (int i=0; i<points.size(); i++) {
        points[i] = points[i].add(a);
    }
}

