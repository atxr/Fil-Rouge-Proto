#include "Physics.h"
#include <iostream>

void Physics::update(Perso *p, Map *map) {
    V2 prev = V2(p->get_position());

    if (p->get_jump()) {
        jump(p, map);
    }
    weight(p, map); 
    inertie(p, map);

    p->set_speed(p->get_position().add(prev.mul(-1)));
}

void Physics::jump(Perso *p, Map *m) {
    p->set_position(p->get_position().add(V2(0, -1.5)));
    p->set_speed(V2(p->get_speed().get_x(), 0));
    p->set_jump(false);
}

void Physics::weight(Perso *p, Map *map) {
    float g = 5e-3;
    p->set_position(p->get_position().add(V2(0,g)));
}

void Physics::inertie(Perso *p, Map *map) {
    float dt = 1;
    std::cout << p->get_speed().get_x() << std::endl;
    p->set_position(p->get_position().add(p->get_speed().mul(dt)));
}

void Physics::getCollisionDist(Perso &, Map) {
}

