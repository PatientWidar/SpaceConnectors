#include "HighscoreManager.h"


void HighscoreManager::load()
{

}

void HighscoreManager::save()
{
    if(changed)
    {
        //save
    }
    else
        return;
}

void HighscoreManager::add(Highscore highscore)
{
    int index = size;
    for(int i = 0; i < size; i++)
    {
        if(highscores[i].score <= highscore.score)
        {
            index = i;
            break;
        }
    }
    if(index == size)
        return;

    for(int i = size-1; i > index; i--)
    {
        highscores[i] = highscores[i-1];
    }
    highscores[index] = highscore;
}

Highscore HighscoreManager::show(int index)
{
    if(index <= this->size && index >= 0)
    {
        return highscores[index];
    }
    else
    {
        throw(std::out_of_range)("HighscoreManager - out of range!");
    }
}