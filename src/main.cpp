#include <SFML/Graphics.hpp>
#include "../include/Spaceship.h"
#include "Coordinate.h"
#include "Asteroids.h"
#define MAX_WIDTH 800
#define MAX_HEIGHT 600
int main()
{
    sf::RenderWindow window(sf::VideoMode(MAX_WIDTH, MAX_HEIGHT), "Asteroids");
    Coordinate::SetFrameSize(MAX_WIDTH,MAX_HEIGHT);
    auto vaisseau = Spaceship{};
    auto asteroid = Asteroids{};
    auto chrono = sf::Clock{};
    while (window.isOpen())
    {
        auto event = sf::Event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        vaisseau.updateState();
        auto tmpChrono = chrono.restart().asSeconds();
        vaisseau.update(tmpChrono);
        asteroid.update(tmpChrono);

        window.clear();
        asteroid.print(window);
        vaisseau.print(window);
        window.display();
    }

    return 0;
}
