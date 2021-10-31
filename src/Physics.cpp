#include "Physics.h"

void Physics::update(Perso *p, Map *map) {
    V2 prev = V2(p->get_position());

    inertie(p, map);
    weight(p, map); 

    p->set_speed(p->get_position().add(prev.mul(-1)));
}

void Physics::weight(Perso *p, Map *map) {
    float g = 0.5;
    p->set_position(p->get_position().add(V2(0,g)));
}

void Physics::inertie(Perso *p, Map *map) {
    float dt = 1e-3;
    p->set_position(p->get_position().add(p->get_speed().mul(dt)));
}

