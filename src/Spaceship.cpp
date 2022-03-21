#include "../include/Spaceship.h"
#include "../include/Speed.h"
#include <iostream>

Spaceship::Spaceship() : Element{"ressources/spaceship.png"}
{

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
