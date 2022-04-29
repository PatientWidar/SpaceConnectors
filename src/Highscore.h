#pragma once
#include <string>


class Highscore
{
    public:
        int score;
        std::string nick;
        Highscore(std::string nick, int score)
        {
            this->score = score;
            this->nick = nick;
        }
        Highscore()
        {
            this->score = 0;
            this->nick = "-";
        }
};