#include "Map.h"

Map::Map()
{
    map_size_x = 0;
    map_size_y = 0;

    srand(time(NULL));
}

Map::~Map()
{
    Clear();
}

void Map::Clear()
{
    map_size_x = 0;
    map_size_y = 0;
    map_mesh.clear();
    block.clear();
}

bool Map::LoadMap(std::string file_name)
{
    if(map_mesh.size() != 0)
    {
        return false;
    }

    std::string extension = "";
    bool save = false;
    for(int i=0; i<file_name.size(); i++)
    {
        if(save)
        {
            extension.push_back(file_name[i]);
        }
        else if(file_name[i] == '.')
        {
            save = true;
        }
    }

    if(extension == "map")
        return LoadMapFromTextFile(file_name);
    else if(extension == "png")
        return LoadMapFromImageFile(file_name);
}

bool Map::LoadMapFromTextFile(std::string file_name)
{
    std::fstream file;
    file.open(file_name.c_str(), std::ios::in);

    if(!file.good())
    {
        return false;
    }

    short int value_from_file = 0;
    while(!file.eof())
    {
        if(map_size_x == 0)
        {
            file >> map_size_x;
        }
        if(map_size_y == 0)
        {
            file >> map_size_y;
        }
        file >> value_from_file;
        map_mesh.push_back(value_from_file);
    }

    file.close();

    return GenerateBlocks();
}

bool Map::LoadMapFromImageFile(std::string file_name)
{
    sf::Image file;
    if(!file.loadFromFile(file_name))
    {
        return false;
    }

    map_size_x = file.getSize().x;
    map_size_y = file.getSize().y;

    for(int y=0; y<map_size_y; y++)
    {
        for(int x=0; x<map_size_x; x++)
        {
            sf::Color pixel_color = file.getPixel(x,y);
            if(pixel_color == sf::Color::White)
            {
                map_mesh.push_back(0);
            }
            else
            {
                map_mesh.push_back(1);
            }
        }
    }

    return GenerateBlocks();
}

bool Map::GenerateBlocks()
{
    if(map_mesh.size() == 0)
    {
        return false;
    }

    unsigned int x=0, y=0;
    std::shared_ptr<sf::RectangleShape> temporary_block;
    for(unsigned int i=0; i<map_mesh.size(); i++)
    {
        temporary_block = std::make_shared<sf::RectangleShape>(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
        temporary_block->setPosition(BLOCK_SIZE*x, BLOCK_SIZE*y);

        switch(map_mesh[i])
        {
        case 0:
        {
            temporary_block->setFillColor(sf::Color(200,200,200));
        }
        break;
        case 1:
        {
            temporary_block->setFillColor(sf::Color(100,100,100));
        }
        break;
        default:
        {
            block.clear();
            return false;
        }
        }

        block.push_back(temporary_block);

        x++;
        if(x >= map_size_x)
        {
            x = 0;
            y++;
        }
    }

    return true;
}

void Map::Draw(sf::RenderWindow& window)
{
    for(unsigned int y=0; y<map_size_y; y++)
    {
        for(unsigned int x=0; x<map_size_x; x++)
        {
            window.draw(*GetBlock(x,y));
        }
    }
}

std::shared_ptr<sf::RectangleShape> Map::GetBlock(unsigned int x, unsigned int y)
{
    unsigned int i = (y*map_size_x)+x;
    if(i < 0 || i > block.size()-1)
    {
        return nullptr;
    }
    return block[i];
}

short int Map::GetMeshField(unsigned int x, unsigned int y)
{
    unsigned int i = (y*map_size_x)+x;
    if(i < 0 || i > map_mesh.size()-1)
    {
        return -1;
    }
    return map_mesh[i];
}

sf::Vector2u Map::GetSize()
{
    return sf::Vector2u(map_size_x, map_size_y);
}

unsigned short int GetBlockSize()
{
    return BLOCK_SIZE;
}

sf::Vector2f Map::GetRandomPoint()
{
    short int rand_x = 0;
    short int rand_y = 0;

    while(GetMeshField(rand_x, rand_y) == 1)
    {
        rand_x = rand()%map_size_x;
        rand_y = rand()%map_size_y;
    }

    rand_x *= BLOCK_SIZE;
    rand_y *= BLOCK_SIZE;

    return sf::Vector2f(rand_x, rand_y);
}
