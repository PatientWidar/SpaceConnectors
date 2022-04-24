#include "GameObject.h"
#include "Highscore.h"
#include <vector>
#include <string>

class Engine
{
    private:
        std::vector<GameObject> game_objects;
        int score;
        string nick;
        float refresh_rate;

    public:
        Engine(
            int score,
            string nick,
            float refresh_rate
        );
        void start();
        void end();
        Highscore get_highscore();
}