#ifndef PHYSICS_H // include guard
#define PHYSICS_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Map.h"
#include "Perso.h"

class Physics {
public:
    void static update(Perso *p, Map* map);

    void static inertie(Perso*, Map*);
    void static weight(Perso*, Map*);

    void static getCollisionDist(Perso&, Map);
};

#endif

