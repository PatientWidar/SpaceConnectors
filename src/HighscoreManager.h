#pragma once
#include "Highscore.h"
#include <stdexcept>

class HighscoreManager
{
    private:
        Highscore highscores[10];
        int size;
        bool changed;

    public:
        HighscoreManager()
        {
            this->size = 10;
            this->changed = false;
        }
        void load();
        void save();
        void add(Highscore highscore);
        Highscore show(int index);
        Highscore operator[](int index)
        {
            return show(index);
        }

};