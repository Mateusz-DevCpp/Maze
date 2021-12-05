#include "Collision.h"

bool Collision::IsCollision(Player& player, sf::RectangleShape obj, sf::Vector2f& offset)
{
    float lp = player.GetPosition().x;
    float rp = player.GetPosition().x + player.GetSize();
    float tp = player.GetPosition().y;
    float bp = player.GetPosition().y + player.GetSize();

    float lo = obj.getPosition().x;
    float ro = obj.getPosition().x + obj.getSize().x;
    float to = obj.getPosition().y;
    float bo = obj.getPosition().y + obj.getSize().x;

    float left = rp - lo;
    float right = ro - lp;
    float top = bp - to;
    float bottom = bo - tp;

    if(left > 0 && right > 0 && top > 0 && bottom > 0)
    {
        left < right ? offset.x = -left : offset.x = right;
        top < bottom ? offset.y = -top : offset.y = bottom;

        if(std::fabs(offset.x) > std::fabs(offset.y))
        {
            offset.x = 0;
        }
        else if(std::fabs(offset.x) < std::fabs(offset.y))
        {
            offset.y = 0;
        }
        else
        {
            offset.x *= 0.5;
            offset.y *= 0.5;
        }

        return true;
    }

    return false;
}

void Collision::RectangleSeparation(Map& map, Player& player)
{
    sf::Vector2f offset;
    for(unsigned int y=0; y<map.GetSize().y; y++)
    {
        for(unsigned int x=0; x<map.GetSize().x; x++)
        {
            if(map.GetMeshField(x,y) == 1)
            {
                if(IsCollision(player, *(map.GetBlock(x,y)), offset))
                {
                    player.ImprovePosition(offset.x, offset.y);
                }
            }
        }
    }
}

bool Collision::Touch(Player& player, sf::RectangleShape& box)
{
    sf::Vector2f non_used;
    return IsCollision(player, box, non_used);
}

