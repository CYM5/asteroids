#ifndef SPEED_H
#define SPEED_H


struct Speed
{
    void operator+=(Speed const& new_speed);
    void operator-=(Speed const& new_speed);
    Speed operator*(float coef) const;
    static Speed CreateNewSpeedVector(float acceleration, float angle);
    float x =0;
    float y =0;
};

#endif // SPEED_H
