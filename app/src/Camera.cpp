#include "Camera.h"

Camera::Camera(const sf::VideoMode& video_mode)
    :video_mode(video_mode)
{
    player_view[0].setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
    player_view[1].setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
    for(int i=0; i<2; i++)
    {
        player_view[i].zoom(0.5);
        player_view[i].setSize(video_mode.width*0.5, video_mode.height);
    }

    screen_separator.setSize(sf::Vector2f(4, video_mode.height));
    screen_separator.setOrigin(2, video_mode.height/2);
    screen_separator.setFillColor(sf::Color::Black);
}

Camera::~Camera()
{

}

void Camera::Update(sf::Vector2f left_center, sf::Vector2f right_center)
{
    player_view[0].setCenter(left_center);
    player_view[1].setCenter(right_center);

    screen_separator.setPosition(left_center.x+(0.25*video_mode.width), left_center.y);
}

void Camera::DrawSeparator(sf::RenderWindow &window)
{
    window.draw(screen_separator);
}

void Camera::SetCamera(sf::RenderWindow &window, int split_screen_id)
{
    window.setView(player_view[split_screen_id]);
}
