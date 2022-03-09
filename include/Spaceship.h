#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include <SFML/Graphics.hpp>
class Spaceship{
    public:
        Spaceship();
        void updateState(sf::Event const& event);
        void update(float loop_time);
        void print(sf::RenderWindow& window) const;
    private:
        sf::Texture m_texture{};
        sf::Sprite m_sprite{};
        float speed = 0;
        bool isAccelerat = false;

        static constexpr float ACCELERATION = 2000;
        static constexpr float FRICTION_COEF = 2;
};

#endif // SPACESHIP_H_INCLUDED
