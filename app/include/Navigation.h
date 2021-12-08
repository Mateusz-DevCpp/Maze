#ifndef __NAVIGATION_H__
#define __NAVIGATION_H__

#include <cmath>

#include <SFML/Graphics.hpp>

#define NAV_WIDTH 50
#define NAV_HEIGHT 50

class Navigation
{
private:
    sf::VideoMode video_mode; //!< Size of window, is used to set position for navigation arrow

    sf::Texture nav_texture; //!< Texture used to show navigation arrow
    sf::Sprite nav[2]; //!< Sprites to display texture Navigation::nav_texture

public:
    /** Default constructor
     * \param video_mode - Information about size of window
     */
    Navigation(sf::VideoMode video_mode);

    /** Default destructor
     */
    ~Navigation();

    /** \brief Set position and rotation for both navigations icons
     * \param player_position_1 - Player 1 position on map
     * \param player_position_2 - Player 2 position on map
     * \param coin_position - Coin position on map
     */
    void UpdateNavigation(sf::Vector2f player_position_1, sf::Vector2f player_position_2, sf::Vector2f coin_position);

    /** \brief Draw navigation on window
     * \param window - Window to render score
     * \param player_id number of player for whose show navigation
     *              0 - player 1
     *              1 - player 2
     */
    void Draw(sf::RenderWindow& window, unsigned short int player_id);
};

#endif // __NAVIGATION_H__
