#include "Map.h"
#include <vector>

Map::Map() : Map({}, {}) {}
Map::Map(std::vector<Perso*> persos, std::vector<Wall*> walls) :
    m_persos(persos), m_walls(walls) {}

std::vector<Perso*> Map::get_persos() { return m_persos; }
std::vector<Wall*> Map::get_walls() { return m_walls; }

void Map::add_perso(Perso *p) {
    m_persos.push_back(p);
}

void Map::add_wall(Wall *w) {
    m_walls.push_back(w);
}

void Map::update() {

}
