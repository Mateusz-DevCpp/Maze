#include "Score.h"

Score::Score(sf::VideoMode video_mode)
{
    this->video_mode = video_mode;
    this->video_mode.width *= 0.5;

    Reset();

    font.loadFromFile("Data/UI/font/arial.ttf");
    for(unsigned short int i=0; i<2; i++)
    {
        score_ui[i].setFont(font);
        score_ui[i].setCharacterSize(32);
        score_ui[i].setFillColor(sf::Color::Black);
    }
}

Score::~Score()
{

}

void Score::Reset()
{
    for(int i=0; i<2; i++)
    {
        player_score_round[i] = 0;
        player_score_math[i] = 0;
    }
}

void Score::Draw(sf::RenderWindow& window, unsigned short int player_id)
{
    window.draw(score_ui[player_id]);
}

void Score::IncrementScore(unsigned short int player_id)
{
    player_score_round[player_id]++;
    if(player_score_round[player_id] == 2)
    {
        player_score_math[player_id]++;
        player_score_round[0] = 0;
        player_score_round[1] = 0;
    }
}

unsigned short int Score::GetScore(unsigned short int player_id)
{
    return 3*player_score_math[player_id]+player_score_round[player_id];
}

void Score::UpdatePosition(sf::Vector2f view_offset_player_1, sf::Vector2f view_offset_player_2)
{
    std::stringstream ss[2];

    ss[0] << player_score_round[0] << ":" << player_score_math[0];
    score_ui[0].setString(ss[0].str());
    score_ui[0].setPosition(view_offset_player_1);
    score_ui[0].move(-0.5*video_mode.width+10, -0.5*video_mode.height+10);

    ss[1] << player_score_round[1] << ":" << player_score_math[1];
    score_ui[1].setString(ss[1].str());
    score_ui[1].setPosition(view_offset_player_2);
    score_ui[1].move(0.5*video_mode.width-15-score_ui[1].getGlobalBounds().width, -0.5*video_mode.height+10);
}

unsigned int Score::WhoWin()
{
    if(GetScore(0) == GetScore(1))
    {
        return 2;
    }
    else if(GetScore(0) > GetScore(1))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
