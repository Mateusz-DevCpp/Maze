#ifndef PLAYERCIRCLE_H
#define PLAYERCIRCLE_H

#include "Player.h"


class PlayerCircle : public Player
{
private:

public:
    /** \brief Default constructor
     */
    PlayerCircle();

    /** \brief Default destructor
     */
    ~PlayerCircle();

    /** \brief Player movement
     */
    void Move() override;
};

#endif // PLAYERCIRCLE_H
