#include "Player.h"

Player::Player()
{
    size = 25;
    speed = 0;
    max_speed = 2.5;
    smooth = 0.95;
    color = sf::Color(0,0,0);
}

Player::~Player()
{

}

float Player::GetSize()
{
    return size;
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(*player);
}

sf::Vector2f Player::GetPosition()
{
    return player->getPosition();
}

void Player::ImprovePosition(float x, float y)
{
    player->move(x,y);
}

void Player::SetPosition(float x, float y)
{
    player->setPosition(x, y);
    player->move(size*0.5, size*0.5);
}

sf::Color Player::GetColor()
{
    return color;
}

void Player::JoystickMove()
{
    if(sf::Joystick::isConnected(0))
    {
        float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

        if(x >= -100 && x < -66) x = -max_speed;
        else if(x >= -66 && x < -33) x = -max_speed*0.5;
        else if(x >= -33 && x < -10) x = -max_speed*0.25;
        else if(x >= 10 && x < 33) x = max_speed*0.25;
        else if(x >= 33 && x < 66) x = max_speed*0.5;
        else if(x >= 66 && x <= 100) x = max_speed;
        else x = 0;

        if(y >= -100 && y < -66) y = -max_speed;
        else if(y >= -66 && y < -33) y = -max_speed*0.5;
        else if(y >= -33 && y < -10) y = -max_speed*0.25;
        else if(y >= 10 && y < 33) y = max_speed*0.25;
        else if(y >= 33 && y < 66) y = max_speed*0.5;
        else if(y >= 66 && y <= 100) y = max_speed;
        else y = 0;

        player->move(x, y);
    }
    else
    {
        std::cerr << "Controller is not connected" << std::endl;
    }
}

void Player::UseJoystick(bool joystick)
{
    use_joystic = joystick;
}
