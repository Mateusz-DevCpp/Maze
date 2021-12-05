#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SFML/Graphics.hpp>

class Camera
{
private:
    sf::View player_1_view; //!< View for left side of split screen
    sf::View player_2_view; //!< View for right side of split screen

public:
    /** \brief Constructor for Camera class
     * \param video_mode - Informations about size of game window
     */
    Camera(const sf::VideoMode& video_mode);

    /** Default destructor */
    ~Camera();

    /** \brief Update view for both side of the split screen
     * \param left_center - New center position for the view to the left of the split screen
     * \param right_center - New center position for the view to the right of the split screen
     */
    void Update(sf::Vector2f left_center, sf::Vector2f right_center);

    /** \brief Update view for both side of the split screen
     * \param window - Reference to the window for which the view is to be set
     * \param split_screen_id - ID number of the part of the split screen
     *              0 - left side
     *              1 - right side
     */
    void SetCamera(sf::RenderWindow &window, int split_screen_id);
};

#endif // __CAMERA_H__
