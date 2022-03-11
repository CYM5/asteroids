#include "Speed.h"
#include <cmath>
void Speed::operator+=(Speed const& new_speed) {
    x += new_speed.x;
    y += new_speed.y;
}

void Speed::operator-=(Speed const& new_speed) {
    x -= new_speed.x;
    y -= new_speed.y;
}

Speed Speed::operator*(float coef) const {
    return Speed{x*coef, y*coef};
}

Speed Speed::CreateNewSpeedVector(float acceleration, float angle){
    return Speed{float(acceleration*cos(angle/180.f * M_PI)), float(acceleration*sin(angle/180.f * M_PI))};
}
