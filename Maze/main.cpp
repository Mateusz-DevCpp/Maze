#include <iostream>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Player.h"
#include "Collision.h"
#include "Coin.h"
#include "Camera.h"

int main()
{
    sf::VideoMode view_mode;
    view_mode.width = 1600;
    view_mode.height = 800;

    sf::RenderWindow window(view_mode, "Labirynt");
    window.setFramerateLimit(120);

    Camera camera(view_mode);

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
            Collision::RectangleSeparation(map, *player[i]);
            if(coin.PickUp(*player[i]))
            {
                player[i]->IncreaseScore();
                map_list_iterator++;
                if(map_list_iterator == 3)
                {
                    map_list_iterator = 0;
                    std::cout << player[0]->GetScore() << " : " << player[1]->GetScore() << std::endl;
                    player[0]->ResetScore();
                    player[1]->ResetScore();
                }
                if(i == 0)
                    window.clear(sf::Color::Blue);
                else
                    window.clear(sf::Color::Red);
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



        window.clear();
        for(unsigned short int i=0; i<2; i++)
        {
            camera.SetCamera(window, i);
            map.Draw(window);
            for(unsigned short int j=0; j<2; j++)
                player[j]->Draw(window);
            coin.Draw(window);
        }
        window.display();
    }

    return 0;
}
