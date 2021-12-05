#ifndef __COLLISION_H__
#define __COLLISION_H__

#include "cmath"

#include "Map.h"
#include "Player.h"

class Collision
{
private:
    /** \brief Checks for a collision
     * \param player - Player for check collision with second parameter
     * \param obj - sf::RectangleShape whose player can collide
     * \param offset - Reference to sf::Vector2f where is saved value of horizontal and vertical
     *              distance how many pixels player need to out from selected rectangle
     * \return collision status
     *              0 / false - if player do not touch box
     *              1 / true - if player touch box
     */
    static bool IsCollision(Player& player, sf::RectangleShape obj, sf::Vector2f& offset);

public:
    /** \brief Separation between map and player
     *              If player is in any block on map, player is moved out from this bloc
     *              This method separate player from rectangle
     * \param player - Player for check collision with second parameter
     * \param map - Map with every block
     */
    static void RectangleSeparation(Map& map, Player& player);


    static void CircleSeparation(Map& map, Player& player);

    /** \brief Checks for a collision
     * \param player - Player for check collision with second parameter
     * \param box - sf::RectangleShape whose player can touch
     * \return collision status
     *              0 / false - if player do not touch box
     *              1 / true - if player touch box
     */
    static bool Touch(Player& player, sf::RectangleShape& box);
};

#endif // __COLLISION_H__
