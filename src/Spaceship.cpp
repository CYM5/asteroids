#include "../include/Spaceship.h"
#include "../include/Speed.h"
#include <iostream>

Spaceship::Spaceship(){
    if (!m_texture.loadFromFile("/home/alex/asteroids/ressources/spaceship.png"))
    {
        std::cerr << "Can't open texture" << std::endl;
        return;
    }
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(0.1,0.1);
    m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
    m_sprite.setPosition(position.getX(), position.getY());


}

void Spaceship::updateState(){
    isAccelerate = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    isLeftRotate = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    isRightRotate = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Spaceship::update(float loop_time){
    if (isAccelerate) {
        speed += Speed::CreateNewSpeedVector(ACCELERATION * loop_time, m_sprite.getRotation());
    }
    speed -= speed *FRICTION_COEF * loop_time; //Deceleration
    Speed target_move = speed*loop_time;
    position += target_move;
    m_sprite.setPosition(position.getX(), position.getY());
    if (isLeftRotate) {
        m_sprite.rotate (- ANGLE * loop_time);
    }
    if (isRightRotate) {
        m_sprite.rotate (ANGLE * loop_time);
    }
}

void Spaceship::print(sf::RenderWindow& window) const{
    window.draw(m_sprite);
}
