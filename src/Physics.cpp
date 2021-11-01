#include "Physics.h"
#include <iostream>
#include <vector>
#include <assert.h>

void Physics::update(Perso *p, Map *map) {
    V2 prev = V2(p->get_position());
    
    if (p->get_jump()) {
        jump(p, map);
    } 

    // Physics
    weight(p, map); 
    inertie(p, map);

    p->set_speed(p->get_position().add(prev.mul(-1)));

    // Controls
    // TODO Here ???
    if (p->get_left()) {
        left(p, map);
    } else if (p->get_right()) {
        right(p, map);
    }
}

void Physics::jump(Perso *p, Map *m) {
    float j = 6;
    V2 mov = V2(0, -j);

    V2 cor = correctionCollision(mov, p, m);
    p->set_position(p->get_position().add(cor));

    p->set_speed(V2(p->get_speed().get_x(), 0));
    p->set_jump(false);
}

// TODO shorter left/right
void Physics::right(Perso *p, Map *m) {
    float j = 5;
    V2 mov = V2(j, 0);

    V2 cor = correctionCollision(mov, p, m);
    p->set_position(p->get_position().add(cor));
}

void Physics::left(Perso *p, Map *m) {
    float j = 5;
    V2 mov = V2(-j, 0);

    V2 cor = correctionCollision(mov, p, m);
    p->set_position(p->get_position().add(cor));
}

void Physics::weight(Perso *p, Map *map) {
    float g = 0.4;
    V2 mov = V2(0,g);

    V2 cor = correctionCollision(mov, p, map);
    p->set_position(p->get_position().add(cor));
}

void Physics::inertie(Perso *p, Map *map) {
    float dt = 1;
    V2 mov = p->get_speed().mul(dt);

    V2 cor = correctionCollision(mov, p, map);
    p->set_position(p->get_position().add(cor));
}

V2 Physics::correctionCollision(V2 mov, Perso* p, Map* m) {
    float min = mov.norm();
    for (auto wall: m->get_walls()) {
        for (auto pts: p->get_hitbox().get_points()) {
            float col = rayRectangle(pts, pts.add(mov), wall->get_hitbox().get_rectangle());
            min = (col != -1 && col<min) ? col : min;
        }
    }

    // if collision
    float epsilon = 1e-4;
    if (min != mov.norm()) { 
        min -= epsilon; // avoid tp inside the wall
    }

    return mov.direction().mul(min);
}

float Physics::rayLine(V2 xa, V2 xb, V2 ya, V2 yb) {
    float x1 = xa.get_x();
    float y1 = xa.get_y();
    float x2 = xb.get_x();
    float y2 = xb.get_y();
    float x3 = ya.get_x();
    float y3 = ya.get_y();
    float x4 = yb.get_x();
    float y4 = yb.get_y();


    // calculate the direction of the lines
    float uA = ((x4-x3)*(y1-y3) - (y4-y3)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));
    float uB = ((x2-x1)*(y1-y3) - (y2-y1)*(x1-x3)) / ((y4-y3)*(x2-x1) - (x4-x3)*(y2-y1));

    // if uA>0 and uB is between 0-1, lines are colliding
    if (uA >= 0 && uB >= 0 && uB <= 1) {
        float intersectionX = x1 + (uA * (x2-x1));
        float intersectionY = y1 + (uA * (y2-y1));
        return V2(intersectionX, intersectionY).sub(xa).norm(); // sub xa origin point
    }

    return -1;
}

float Physics::rayRectangle(V2 xa, V2 xb, std::vector<V2> rect) {
    float col = -1;
    for (int i=0; i<4; i++) {
        float min = rayLine(xa, xb, rect[i], rect[(i+1)%4]);
        if (i==0)
        col = (col == -1 || (min != -1 && min < col)) ? min : col; 
    }

    return col;
}
