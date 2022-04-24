#include "GameObject.h"


class Bullet : public GameObject
{
    private:
        float damage;
    
    public:
        Bullet(
            Point position, 
            float speed, 
            //type model,
            string color,
            //pointer_to_object object,
            char[] direction,
            float y_border,
            float damage
        );
        int deal_damage(SpaceShip& ship)
        {
            return ship->deal_damage(this->damage);
        }
}