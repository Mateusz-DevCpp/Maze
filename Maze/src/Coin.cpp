#include "Coin.h"

Coin::Coin()
{
    size = 20;
    coin.setFillColor(sf::Color::Yellow);
    coin.setSize(sf::Vector2f(size, size));
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
    coin.move(size*0.5, size*0.5);
}
