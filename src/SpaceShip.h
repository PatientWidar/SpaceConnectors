#pragma once
#include "GameObject.h"


class SpaceShip : public GameObject
{
    private:
        float shot_energy;
        float energy;
        float hp;
        int score;
        int check_hp();

    public:
        SpaceShip(
            Point position, 
            float speed, 
            std::string color,
            char direction[2],
            float y_border,
            float x_border,
            float shot_energy,
            float start_energy,
            float hp,
            int score,
            const char* texture,
            SDL_Renderer* ren
        );

        int get_hp()
        {
            return hp;
        }

        Point shot();
        void refill_energy(float refilled_energy)
        {
            if(shot_energy > this->energy)
                this->energy += refilled_energy;
        }

        void change_dir(char direction[2])
        {
            this->direction[0] = direction[0];
            this->direction[1] = direction[1];
        }

        // Return points if ship get destroyed
        int get_damage(float damage)
        {
            this->hp -= damage;
            return check_hp();
        }

        bool got_hit(Point positions[2])
        {
            if((positions[0].x > position.x && positions[0].x < position.x + width) || (positions[1].x > position.x && positions[1].x < position.x + width))
                if((positions[0].y > position.y && positions[0].y < position.y + height) || (positions[1].y > position.y && positions[1].y < position.y + height))
                    return true;
            return false;
        }
};