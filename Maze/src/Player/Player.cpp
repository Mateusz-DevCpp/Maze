#include "Player.h"

Player::Player()
{
    size = 25;
    speed = 2.5;
    score = 0;
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

bool Player::IsHorizontalMove()
{
    return horizontal_move;
}

bool Player::IsVerticalMove()
{
    return vertical_move;
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

unsigned short int Player::GetScore()
{
    return score;
}

void Player::IncreaseScore()
{
    score++;
}

void Player::ResetScore()
{
    score = 0;
}
