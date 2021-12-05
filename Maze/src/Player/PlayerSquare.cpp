#include "PlayerSquare.h"

PlayerSquare::PlayerSquare()
    :Player()
{
    player = std::make_shared<sf::RectangleShape>(sf::Vector2f(size, size));
    player->setFillColor(sf::Color::Blue);
    player->move(63,63);
}

PlayerSquare::~PlayerSquare()
{

}

void PlayerSquare::Move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player->move(0, -speed);
        vertical_move = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player->move(0, speed);
        vertical_move = true;
    }
    else
    {
        vertical_move = false;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->move(-speed, 0);
        horizontal_move = true;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->move(speed, 0);
        horizontal_move = true;
    }
    else
    {
        horizontal_move = false;
    }
}
