#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <memory>

#include <SFML/Graphics.hpp>

class Player
{
protected:
    std::shared_ptr<sf::Shape> player; //!< A shape whose representing the player
    float size; //!< Player size
    float speed; //!< Player speed (px per frame)
    sf::Color color; //!< Color of shape representing player

public:
    /** \brief Default constructor */
    Player();

    /** \brief Default destructor */
    virtual ~Player();

    /** \brief Access size
     * \return The current value of size
     */
    float GetSize();

    /** \brief Access player
     * \return The current position of player
     */
    sf::Vector2f GetPosition();

    /** \brief Draw player
     * \param window - Window to render player
     */
    void Draw(sf::RenderWindow& window);

    /** \brief Player movement */
    virtual void Move()=0;

    /** \brief Improve player position
     * \param x - New horizontal position
     * \param y - New vertical position
     */
    void SetPosition(float x, float y);

    /** \brief Improve player position
     *          Method for Collision class to improve player position
     * \param x - Value of player offset in horizontal position
     * \param y - Value of player offset in vertical position
     */
    void ImprovePosition(float x, float y);

    /** \brief Information about player color
     * \return color in sf::Color of player
     */
    sf::Color GetColor();
};

#include "PlayerCircle.h"
#include "PlayerSquare.h"

#endif // __PLAYER_H__
