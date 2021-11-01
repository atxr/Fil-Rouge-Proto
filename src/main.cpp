#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
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
    
    int i=0;

    sf::Clock timer_fps;
    float FPS = 50;

    while (window.isOpen())
    {
        float ft = timer_fps.restart().asMilliseconds();
        if (ft > 1000/FPS)
            cout << "Frame time low: " << ft << "ms instead of " << 1000/FPS << endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        map.update();

        sf::CircleShape circle = sf::CircleShape(1);
        circle.setOrigin(1,1);
        circle.setFillColor(sf::Color::Yellow);
        
        for (auto player: map.get_persos()) {
            window.draw(player->get_sprite());

            for (auto p: player->get_hitbox().get_points()) {
                circle.setPosition(p.get_x(), p.get_y());
                window.draw(circle);
            }
        }
        
        for (auto wall: map.get_walls()) {
            window.draw(wall->get_sprite());
            for (auto p: wall->get_hitbox().get_points()) {
                circle.setPosition(p.get_x(), p.get_y());
                window.draw(circle);
            }
        }

        window.display();
        i++;
        if (i==100) {
            cout << "jump" << endl;
            map.get_persos()[0]->set_jump(true);
        }

        while (timer_fps.getElapsedTime().asMilliseconds() < 1000/FPS) {}
    }
	return 0;
}

