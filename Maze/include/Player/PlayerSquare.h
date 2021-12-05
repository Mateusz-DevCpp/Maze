#ifndef __PLAYERSQUARE_H__
#define __PLAYERSQUARE_H__

#include "Player.h"


class PlayerSquare : public Player
{
private:


public:
    /** \brief Default constructor */
    PlayerSquare();

    /** \brief Default destructor */
    ~PlayerSquare();

    /** \brief Player movement */
    void Move() override;
};

#endif // __PLAYERSQUARE_H__
