#include "Highscore.h"
#include <stdexcept>

class HighscoreManager
{
    private:
        Highscore[10] highscores;
        int size;
        bool changed;

    public:
        HighscoreManager()
        {
            this->size = 10;
            this->changed = false;
            this->highscores = new Highscore[size];
        }
        void load();
        void save();
        void add(Highscore highscore);
        Highscore show(int index);
        Highscore operator[](int index)
        {
            return show(index);
        }

}