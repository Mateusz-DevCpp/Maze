#ifndef __SCORE_H__
#define __SCORE_H__

#include <sstream>

#include <SFML/Graphics.hpp>

class Score
{
private:
    unsigned short int player_score_round[2]; //!< Amount of collected coins by player
    unsigned short int player_score_math[2]; //!< Amount of collected coins by player

    sf::Text score_ui[2]; //!< Text with score to display
    sf::Font font; //!< Font used by Score::score_ui

    sf::VideoMode video_mode; //!< Size of window, is used to set position for score
public:
    /** Default constructor
     * \param video_mode - Information about size of window
     */
    Score(sf::VideoMode video_mode);

    /** Default destructor
     */
    ~Score();

    /** \brief Reset score for both player to value 0
     */
    void Reset();

    /** \brief Update position of display score
     * \param view_offset_player_1 - Value of offset from point 0,0 to player 1 camera center
     * \param view_offset_player_2 - Value of offset from point 0,0 to player 2 camera center
     */
    void UpdatePosition(sf::Vector2f view_offset_player_1, sf::Vector2f view_offset_player_2);

    /** \brief Draw score on window
     * \param window - Window to render score
     * \param player_id number of player for whose show score
     *              0 - player 1
     *              1 - player 2
     */
    void Draw(sf::RenderWindow& window, unsigned short int player_id);

    /** \brief Access score
     *          Increase amount of collected coins
     * \param player_id number of player whose get point
     *              0 - player 1
     *              1 - player 2
     */
    void IncrementScore(unsigned short int player_id);

    /** \brief Access score
     * \param player_id number of player whose points to be returned
     *              0 - player 1
     *              1 - player 2
     * \return amount of collected coins by selected player
     */
    unsigned short int GetScore(unsigned short int player_id);

    /** \brief Information, whose about have more points
     * \return ID player with more points
     *              0 - player 1
     *              1 - player 2
     *              2 - player 1 and player 2 have the same score
     */
    unsigned int WhoWin();
};

#endif // __SCORE_H__
