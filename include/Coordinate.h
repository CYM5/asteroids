#ifndef COORDINATE_H
#define COORDINATE_H

#include "Speed.h"
extern float max_width;
extern float max_height;
class Coordinate
{
    public:
        float getX();
        float getY();
        static void SetFrameSize(float width, float height);
        void operator+=(Speed const& speed);
    private:
        float m_x = 100;
        float m_y = 510;
};

#endif // COORDINATE_H
