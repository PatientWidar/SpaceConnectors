#pragma once
#include "GameObject.h"
#include "SpaceShip.h"


class Bullet : public GameObject
{
    private:
        float damage;
        bool enemy;
    
    public:
        Bullet(
            Point position, 
            float speed, 
            std::string color,
            char direction[2],
            float y_border,
            float x_border,
            float damage,
            const char* texture,
            SDL_Renderer* ren,
            int width,
            int height,
            bool enemy
        );
        int deal_damage(SpaceShip& ship)
        {
            Point pos2[2];
            pos2[0] = position;
            pos2[1] = Point(position.x + width, position.y + height);
            if(ship.got_hit(pos2))
                return ship.get_damage(this->damage);
            return 0;
        }
        bool isEnemy()
        {
            return enemy;
        }
};