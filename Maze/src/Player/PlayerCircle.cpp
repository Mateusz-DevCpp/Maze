#include "PlayerCircle.h"

PlayerCircle::PlayerCircle()
    :Player()
{
    player = std::make_shared<sf::CircleShape>(size/2);
    player->setFillColor(sf::Color::Red);
    player->move(63,63);
}

PlayerCircle::~PlayerCircle()
{

}

void PlayerCircle::Move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player->move(0, -speed);
        vertical_move = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player->move(0, speed);
        vertical_move = true;
    }
    else
    {
        vertical_move = false;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player->move(-speed, 0);
        horizontal_move = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player->move(speed, 0);
        horizontal_move = true;
    }
    else
    {
        horizontal_move = false;
    }
}
