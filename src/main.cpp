#include <SFML/Graphics.hpp>
#include "../include/Spaceship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids");
    auto vaisseau = Spaceship{};
    auto chrono = sf::Clock{};
    while (window.isOpen())
    {
        auto event = sf::Event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            vaisseau.updateState(event);
        }

        vaisseau.update(chrono.restart().asSeconds());

        window.clear();
        vaisseau.print(window);
        window.display();
    }

    return 0;
}
