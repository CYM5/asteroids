#include "Coordinate.h"
float max_width = 0;
float max_height = 0;

Coordinate::Coordinate(float x, float y) {
    m_x =x;
    m_y = y;
}
float Coordinate::getX(){
    return m_x;
}

float Coordinate::getY(){
    return m_y;
}

void Coordinate::SetFrameSize(float width, float height){
    max_width = width;
    max_height = height;
}

void Coordinate::operator+=(Speed const& speed) {
    m_x += speed.x;
    m_y += speed.y;
    if (m_x > max_width) {
        m_x = 0;
    }
    if (m_x < 0) {
        m_x = max_width;
    }
    if (m_y > max_height) {
        m_y = 0;
    }
    if (m_y < 0) {
        m_y = max_height;
    }
}
