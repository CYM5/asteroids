#include "Element.h"

#include <iostream>
Element::Element(std::string const& imagePath)
{
    if (!m_texture.loadFromFile(imagePath))
    {
        std::cerr << "Can't open texture" << imagePath << std::endl;
        return;
    }
    m_sprite.setTexture(m_texture);
    //m_sprite.setScale(0.1,0.1);
    m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
    m_sprite.setPosition(position.getX(), position.getY());

}

void Element::update(float loop_time){
    Speed target_move = speed*loop_time;
    position += target_move;
    m_sprite.setPosition(position.getX(), position.getY());
}

void Element::print(sf::RenderWindow& window) const{
    auto printInAllDirectrion = std::array<Speed, 9>{Speed{-1,-1}, Speed{-1,0}, Speed{-1,1}, Speed{0,-1}, Speed{0,0}, Speed{0,1}, Speed{1,-1}, Speed{1,0}, Speed{1,1}};
    for(auto& oneDirection : printInAllDirectrion){
        auto transformation = sf::Transform{};
        transformation.translate(oneDirection.x * max_width, oneDirection.y * max_height);
        window.draw(m_sprite, transformation);
    }

}
