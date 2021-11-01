#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
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
    
    sf::Clock timer_fps;
    float FPS = 60;

    while (window.isOpen())
    {
        float ft = timer_fps.restart().asMilliseconds();
//      if (ft > 1000/FPS)
//          cout << "Frame time low: " << ft << "ms instead of " << 1000/FPS << endl;

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                {
                    if (event.key.code == sf::Keyboard::Up) {
                        map.get_persos()[0]->set_jump(true);
                    }

                    if (event.key.code == sf::Keyboard::Left) {
                        map.get_persos()[0]->set_left(true);
                    }

                    if (event.key.code == sf::Keyboard::Right) {
                        map.get_persos()[0]->set_right(true);
                    }

                    break;
                }

                // key released
                case sf::Event::KeyReleased:
                {
                    if (event.key.code == sf::Keyboard::Left) {
                        map.get_persos()[0]->set_left(false);
                    }

                    if (event.key.code == sf::Keyboard::Right) {
                        map.get_persos()[0]->set_right(false);
                    }

                    break;
                }

                // we don't process other types of events
                default:
                    break;
            }
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

        while (timer_fps.getElapsedTime().asMilliseconds() < 1000/FPS) {}
    }
	return 0;
}

