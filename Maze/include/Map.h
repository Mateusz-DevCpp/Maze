#ifndef __MAP_H__
#define __MAP_H__

#include <fstream>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#define BLOCK_SIZE 50

class Map
{
private:
    unsigned int map_size_x; //!< Size of map (x)
    unsigned int map_size_y; //!< Size of map (y)
    std::vector<short int> map_mesh; //!< Informations about blocks
    std::vector<std::shared_ptr<sf::RectangleShape>> block; //!< The blocks the map is made of

private:
    /** \brief Load map from file
     *              .txt or .map file
     *              this method is used in Map::LoadMap
     * \param file_name - Path to file with map
     * \return Load from file status
     *              0 / false - load fail
     *              1 / true - load success
     */
    bool LoadMapFromTextFile(std::string file_name);

    /** \brief Load map from file
     *              .png file
     *              this method is used in Map::LoadMap
     * \param file_name - Path to file with map
     * \return Load from file status
     *              0 / false - load fail
     *              1 / true - load success
     */
    bool LoadMapFromImageFile(std::string file_name);

    /** \brief Generate blocks list using map_mesh
     * \return Generate blocks status
     *              0 / false - generate fail
     *              1 / true - generate success
     */
    bool GenerateBlocks();

public:
    /** \brief Default constructor */
    Map();

    /** \brief Default destructor */
    ~Map();

    /** \brief Load map from file
     * \param file_name - Path to file with map
     * \return Load from file status
     *              0 / false - load fail
     *              1 / true - load success
     */
    bool LoadMap(std::string file_name);

    /** \brief Clear map
     *              remove everything and set attributes to 0
     */
    void Clear();

    /** \brief Draw map
     * \param window - Window to render map
     */
    void Draw(sf::RenderWindow& window);

    /** \brief Access to blocks
     * \param x - Horizontal block offset
     * \param y - Vertical block offset
     * \return Pointer to selected block
     *              if selected block is valid return nullptr
     */
    std::shared_ptr<sf::RectangleShape> GetBlock(unsigned int x, unsigned int y);

    /** \brief Access to mesh
     * \param x - Horizontal field offset
     * \param y - Vertical field offset
     * \return Value of selected field
     *              if selected field is valid return -1
     */
    short int GetMeshField(unsigned int x, unsigned int y);

    /** \brief Access to map size
     * \return sf::vector2u with map size
     *              GetSize().x is horizontal map size
     *              GetSize().y is vertical map size
     */
    sf::Vector2u GetSize();

    /** \brief Informations about blocks
     * \return size of blocs
     */
    unsigned short int GetBlockSize();

    /** \brief Get random position on map, where block is not collider
     * \return sf::vector2f with free place
     */
    sf::Vector2f GetRandomPoint();
};

#endif // __MAP_H__
