#include <string>


class Highscore
{
    public:
        int score;
        string nick;
        Highscore(string nick, int score)
        {
            this->score = score;
            this->nick = nick;
        }
}