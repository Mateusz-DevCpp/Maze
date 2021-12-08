#include "Collision.h"

bool Collision::IsCollisionRectangle(Player& player, sf::RectangleShape obj, sf::Vector2f& offset)
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
                if(IsCollisionRectangle(player, *(map.GetBlock(x,y)), offset))
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
    return IsCollisionRectangle(player, box, non_used);
}


void Collision::CircleSeparation(Map& map, Player& player)
{
    sf::Vector2f offset;
    for(unsigned int y=0; y<map.GetSize().y; y++)
    {
        for(unsigned int x=0; x<map.GetSize().x; x++)
        {
            if(map.GetMeshField(x,y) == 1)
            {
                if(IsCollisionCircle(player, *(map.GetBlock(x,y)), offset))
                {
                    player.ImprovePosition(offset.x, offset.y);
                }
            }
        }
    }
}

bool Collision::IsCollisionCircle(Player& player, sf::RectangleShape obj, sf::Vector2f& offset)
{
    float cxp = player.GetPosition().x + (0.5*player.GetSize());
    float cyp = player.GetPosition().y + (0.5*player.GetSize());

    float lo = obj.getPosition().x;
    float ro = obj.getPosition().x + obj.getSize().x;
    float to = obj.getPosition().y;
    float bo = obj.getPosition().y + obj.getSize().x;


    sf::Vector2f point_close_circe_center = sf::Vector2f(Clam(cxp, lo, ro), Clam(cyp, to, bo));

    if(VectorLength(cxp, cyp, point_close_circe_center) < (0.5*player.GetSize()))
    {
        if((cxp == point_close_circe_center.x)||
            (cyp == point_close_circe_center.y))
        {
            float left = cxp - lo + (0.5*player.GetSize());
            float right = ro - cxp + (0.5*player.GetSize());
            float top = cyp - to + (0.5*player.GetSize());
            float bottom = bo - cyp + (0.5*player.GetSize());

            left < right ? offset.x = -left : offset.x = right;
            top < bottom ? offset.y = -top : offset.y = bottom;
        }
        else
        {
            offset.x =
                (cxp - point_close_circe_center.x)/
                VectorLength(cxp, cyp, point_close_circe_center)*
                ((0.5*player.GetSize())-VectorLength(cxp, cyp, point_close_circe_center));

            offset.y =
                (cyp - point_close_circe_center.y)/
                VectorLength(cxp, cyp, point_close_circe_center)*
                ((0.5*player.GetSize())-VectorLength(cxp, cyp, point_close_circe_center));
        }

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

float Collision::Clam(float x, float min, float max)
{
    if(x < min)
    {
        return min;
    }
    else if(min < x && x < max)
    {
        return x;
    }
    else if(max < x)
    {
        return max;
    }

    return 0;
}

float Collision::VectorLength(sf::Vector2f v1, sf::Vector2f v2)
{
    return VectorLength(v1.x, v1.y, v2.x, v2.y);
}

float Collision::VectorLength(float x1, float y1, sf::Vector2f v2)
{
    return VectorLength(x1, y1, v2.x, v2.y);
}

float Collision::VectorLength(float x1, float y1, float x2, float y2)
{
    return std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
