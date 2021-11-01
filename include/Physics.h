#ifndef PHYSICS_H // include guard
#define PHYSICS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Math.h"
#include "Map.h"
#include "Perso.h"

class Physics {
public:
    void static update(Perso *p, Map* map);

    void static jump(Perso*, Map*);
    void static left(Perso*, Map*);
    void static right(Perso*, Map*);
    void static inertie(Perso*, Map*);
    void static weight(Perso*, Map*);

    V2 static correctionCollision(V2, Perso*, Map*);
    float static rayLine(V2 xa, V2 xb, V2 ya, V2 yb);
    float static rayRectangle(V2 xa, V2 xb, std::vector<V2>);
};

#endif

