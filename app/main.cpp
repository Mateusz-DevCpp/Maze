#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Player.h"
#include "Collision.h"
#include "Coin.h"
#include "Camera.h"
#include "Navigation.h"
#include "Score.h"

int main()
{
    sf::VideoMode video_mode;
    video_mode.width = 1000;
    video_mode.height = 800;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(video_mode, "Labirynt", sf::Style::Default, settings);
    window.setFramerateLimit(120);

    Camera camera(video_mode);

    std::shared_ptr<Player> player[2];
    player[0] = std::make_shared<PlayerSquare>();
    player[1] = std::make_shared<PlayerCircle>();

    std::vector<std::string> map_list = {"Data/Maps/map_1.png", "Data/Maps/map_2.png", "Data/Maps/map_3.png"};
    unsigned short int map_list_iterator = 0;
    Map map;
    map.LoadMap(map_list[map_list_iterator]);

    sf::Vector2f spawn = map.GetRandomPoint();
    player[0]->SetPosition(spawn.x, spawn.y);
    spawn = map.GetRandomPoint();
    player[1]->SetPosition(spawn.x, spawn.y);

    Coin coin;
    spawn = map.GetRandomPoint();
    coin.SetPosition(spawn.x, spawn.y);

    Score score(video_mode);
    Navigation nav(video_mode);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                {
                    window.close();
                }
                break;

            default:
                ;
            }
        }



        for(unsigned short int i=0; i<2; i++)
        {
            player[i]->Move();
            if(i==0)
                Collision::RectangleSeparation(map, *player[i]);
            else
                Collision::CircleSeparation(map, *player[i]);

            if(coin.PickUp(*player[i]))
            {
                score.IncrementScore(i);
                map_list_iterator++;
                if(map_list_iterator == 3)
                {
                    map_list_iterator = 0;
                }

                window.clear(player[i]->GetColor());
                window.display();
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                map.Clear();

                map.LoadMap(map_list[map_list_iterator]);
                sf::Vector2f spawn = map.GetRandomPoint();
                player[0]->SetPosition(spawn.x, spawn.y);
                spawn = map.GetRandomPoint();
                player[1]->SetPosition(spawn.x, spawn.y);
                spawn = map.GetRandomPoint();
                coin.SetPosition(spawn.x, spawn.y);
            }
        }

        camera.Update(player[0]->GetPosition(), player[1]->GetPosition());
        score.UpdatePosition(player[0]->GetPosition(), player[1]->GetPosition());
        nav.UpdateNavigation(player[0]->GetPosition(), player[1]->GetPosition(), coin.GetPosition());



        window.clear(sf::Color(100,100,100));
        for(unsigned short int i=0; i<2; i++)
        {
            camera.SetCamera(window, i);
            map.Draw(window);
            for(unsigned short int j=0; j<2; j++)
                player[j]->Draw(window);
            coin.Draw(window);
            score.Draw(window, i);
            nav.Draw(window, i);
            if(i == 0)
            {
                camera.DrawSeparator(window);
            }
        }
        window.display();
    }

    return 0;
}
