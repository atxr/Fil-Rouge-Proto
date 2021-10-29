#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Perso.h"
#include "Map.h"
#include "Wall.h"
#include "Physics.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "sfml-app");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Map map = Map();
    map.add_perso(new Perso);
    map.add_wall(new Wall);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        map.update();
        for (auto player: map.get_persos()) {
            window.draw(player->get_sprite());
            cout << player->get_position().get_x() << " " << player->get_position().get_y() << endl;
        }

        for (auto wall: map.get_walls()) {
            window.draw(wall->get_sprite());
            cout << wall->get_position().get_x() << " " << wall->get_position().get_y() << endl;
        }

        window.display();
    }
	return 0;
}

