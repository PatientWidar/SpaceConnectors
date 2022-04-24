#include "Engine.h"

Engine::Engine(
    int score,
    string nick,
    float refresh_rate
)
{
    this->score = score;
    this->nick = nick;
    this->refresh_rate = refresh_rate;
}

void Engine::start()
{
    score = 0;
}

void Engine::end()
{

}

Highscore get_highscore()
{
    return Highscore(nick, score);
}