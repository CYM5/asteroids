#ifndef ELEMENT_H
#define ELEMENT_H

#include <SFML/Graphics.hpp>
#include "Speed.h"
#include "Coordinate.h"

class Element
{
    public:
        Element(std::string const& imagePath);
        void update(float loop_time);
        void print(sf::RenderWindow& window) const;
    protected:
        sf::Texture m_texture{};
        sf::Sprite m_sprite{};
        Speed speed = {0, 0};
        Coordinate position{100, 100};
};

#endif // ELEMENT_H
