#include "PlayerSquare.h"

PlayerSquare::PlayerSquare()
    :Player()
{
    color = sf::Color(0,0,255);
    player = std::make_shared<sf::RectangleShape>(sf::Vector2f(size, size));
    player->setFillColor(color);
    player->move(63,63);
}

PlayerSquare::~PlayerSquare()
{

}

void PlayerSquare::Move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player->move(0, -speed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player->move(0, speed);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player->move(-speed, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player->move(speed, 0);
    }
}
