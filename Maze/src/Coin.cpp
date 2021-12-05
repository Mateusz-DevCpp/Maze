#include "Coin.h"

Coin::Coin()
{
    coin.setFillColor(sf::Color::Yellow);
    coin.setSize(sf::Vector2f(20,20));
}

Coin::~Coin()
{
    //dtor
}

void Coin::Draw(sf::RenderWindow& window)
{
    window.draw(coin);
}

bool Coin::PickUp(Player& player)
{
    if(Collision::Touch(player, coin))
    {
        coin.setPosition(-100, -100);
        return true;
    }
    return false;
}

void Coin::SetPosition(float x, float y)
{
    coin.setPosition(x, y);
}
