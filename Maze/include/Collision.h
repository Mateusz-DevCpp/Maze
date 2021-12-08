#ifndef __COLLISION_H__
#define __COLLISION_H__

#include "cmath"

#include "Map.h"
#include "Player.h"

class Collision
{
private:
    /** \brief Checks for a collision when player is a rectangle
     * \param player - Player for check collision with second parameter
     * \param obj - sf::RectangleShape whose player can collide
     * \param offset - Reference to sf::Vector2f where is saved value of horizontal and vertical
     *              distance how many pixels player need to out from selected rectangle
     * \return collision status
     *              0 / false - if player do not touch box
     *              1 / true - if player touch box
     */
    static bool IsCollisionRectangle(Player& player, sf::RectangleShape obj, sf::Vector2f& offset);

    /** \brief Checks for a collision when player is a circle
     * \param player - Player for check collision with second parameter
     * \param obj - sf::RectangleShape whose player can collide
     * \param offset - Reference to sf::Vector2f where is saved value of horizontal and vertical
     *              distance how many pixels player need to out from selected rectangle
     * \return collision status
     *              0 / false - if player do not touch box
     *              1 / true - if player touch box
     */
    static bool IsCollisionCircle(Player& player, sf::RectangleShape obj, sf::Vector2f& offset);

    /** \brief Clamping function
     * \param x - The value to clamp
     * \param min - the boundaries to clamp x to
     * \param max - the boundaries to clamp x to
     * \return value of min if x is less than min,
     *          value of max if x is larger than max,
     *          value of x if x is in range <min; max>.
     */
    static float Clam(float x, float min, float max);

    /** \brief Calculate distance between two point (id 2D)
     * \param v1 - Coordinates of first point
     * \param v2 - Coordinates of second point
     * \return distance between those two points
     */
    static float VectorLength(sf::Vector2f v1, sf::Vector2f v2);

    /** \brief Calculate distance between two point (id 2D)
     * \param x1 - X coordinate of first point
     * \param y1 - Y coordinate of first point
     * \param v2 - Coordinates of second point
     * \return distance between those two points
     */
    static float VectorLength(float x1, float y1, sf::Vector2f v2);

    /** \brief Calculate distance between two point (id 2D)
     * \param x1 - X coordinate of first point
     * \param y1 - Y coordinate of first point
     * \param x2 - X coordinate of second point
     * \param y2 - Y coordinate of second point
     * \return distance between those two points
     */
    static float VectorLength(float x1, float y1, float x2, float y2);

public:
    /** \brief Separation between map and player when player is a rectangle
     *              If player is in any block on map, player is moved out from this block
     *              This method separate player from rectangle
     * \param player - Player for check collision with second parameter
     * \param map - Map with every block
     */
    static void RectangleSeparation(Map& map, Player& player);

    /** \brief Separation between map and player when player is a circle
     *              If player is in any block on map, player is moved out from this block
     *              This method separate player from rectangle
     * \param player - Player for check collision with second parameter
     * \param map - Map with every block
     */
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
