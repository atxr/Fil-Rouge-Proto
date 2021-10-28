#include <iostream>
#include <SFML/Graphics.hpp>
#include "Perso.h"
#include "Map.h"
#include "Physics.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 500), "sfml-app");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Perso *player = new Perso("Alex");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        cout << player->get_position().x <<  " " << player->get_position().y << endl;
        window.draw(player->get_sprite());
        window.display();
    }
	return 0;
}

