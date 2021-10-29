#ifndef MAP_H // include guard
#define MAP_H

#include "Perso.h"
#include "Wall.h"
#include <vector>

class Map {
public:
    Map();
    Map(std::vector<Perso*> persos, std::vector<Wall*> walls);

    std::vector<Perso*> get_persos();
    std::vector<Wall*> get_walls();

    void add_perso(Perso* p);
    void add_wall(Wall* w);

    void update();

private:
    std::vector<Perso*> m_persos;
    std::vector<Wall*> m_walls;
};

#endif

