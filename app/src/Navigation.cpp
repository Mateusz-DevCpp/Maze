#include "Navigation.h"

Navigation::Navigation(sf::VideoMode video_mode)
{
    this->video_mode = video_mode;
    this->video_mode.width *= 0.5;

    nav_texture.loadFromFile("Data/UI/Nav.png");
    nav_texture.setSmooth(true);

    for(unsigned short int i=0; i<2; i++)
    {
        nav[i].setTexture(nav_texture);
        nav[i].setOrigin(0.5*nav[i].getGlobalBounds().width, 0.5*nav[i].getGlobalBounds().height);
    }
}

Navigation::~Navigation()
{

}

void Navigation::UpdateNavigation(sf::Vector2f player_position_1, sf::Vector2f player_position_2, sf::Vector2f coin_position)
{
    sf::Vector2f player_position[2] = {player_position_1, player_position_2};

    double delta_x=0, delta_y=0, nav_angle=0;
    for(unsigned short int i=0; i<2; i++)
    {
        nav[i].setPosition(player_position[i]);
        nav[i].move(-0.5*NAV_WIDTH, -0.5*video_mode.height+35);

        delta_x = player_position[i].x - coin_position.x;
        delta_y = player_position[i].y - coin_position.y;
        nav_angle = std::atan2(delta_y, delta_x);

        nav_angle = nav_angle * (180.0/M_PI);
        nav[i].setRotation(nav_angle);
    }
}

void Navigation::Draw(sf::RenderWindow& window, unsigned short int player_id)
{
    window.draw(nav[player_id]);
}
