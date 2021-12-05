#include "Camera.h"

Camera::Camera(const sf::VideoMode& video_mode)
{
    player_1_view.zoom(0.5);
    player_2_view.zoom(0.5);
    player_1_view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
    player_2_view.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
    player_1_view.setSize(video_mode.width*0.5, video_mode.height);
    player_2_view.setSize(video_mode.width*0.5, video_mode.height);
}

Camera::~Camera()
{

}

void Camera::Update(sf::Vector2f left_center, sf::Vector2f right_center)
{
    player_1_view.setCenter(left_center.x, left_center.y);
    player_2_view.setCenter(right_center.x, right_center.y);
}

void Camera::SetCamera(sf::RenderWindow &window, int split_screen_id)
{
    if(split_screen_id == 0)
    {
        window.setView(player_1_view);
    }
    else
    {
        window.setView(player_2_view);
    }
}
