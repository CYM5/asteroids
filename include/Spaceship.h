#ifndef SPACESHIP_H_INCLUDED
#define SPACESHIP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Speed.h"
#include "Coordinate.h"
#include "Element.h"
class Spaceship : public Element{
    public:
        Spaceship();
        void updateState();
        void update(float loop_time);
    private:
        bool isAccelerate = false;
        bool isLeftRotate = false;
        bool isRightRotate = false;

        static constexpr float ACCELERATION = 2000;
        static constexpr float FRICTION_COEF = 2;
        static constexpr float ANGLE = 70;
};

#endif // SPACESHIP_H_INCLUDED
