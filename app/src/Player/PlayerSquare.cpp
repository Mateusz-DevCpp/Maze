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
    if(use_joystic)
    {
        JoystickMove();
    }
    else
    {
        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
                !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            speed = 0;
        }
        else
        {
            speed = max_speed * (1 - smooth) + speed * smooth;
        }

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
}
