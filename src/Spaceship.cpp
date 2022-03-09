#include "../include/Spaceship.h"
#include <iostream>

Spaceship::Spaceship(){
    if (!m_texture.loadFromFile("/home/cyms/Documents/code/asteroids/ressources/spaceship.png"))
    {
        std::cerr << "Can't open texture" << std::endl;
        return;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.1,0.1);

}

void Spaceship::updateState(sf::Event const& event){

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up){
        isAccelerat=true;
    }
    else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
    {
        isAccelerat=false;
    }
}

void Spaceship::update(float loop_time){
    if (isAccelerat==true) {
        speed += ACCELERATION * loop_time;
    }
    speed -= speed *FRICTION_COEF * loop_time; //Deceleration
    m_sprite.move(speed*loop_time, 0);
}

void Spaceship::print(sf::RenderWindow& window) const{
    window.draw(m_sprite);
}
