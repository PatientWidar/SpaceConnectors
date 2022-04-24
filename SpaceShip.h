#include "GameObject.h"
#include "Bullet.h"

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
            //type model,
            string color,
            //pointer_to_object object,
            char[] direction,
            float y_border,
            float shot_energy,
            float start_energy,
            float hp,
            int score
        );

        Bullet shot();
        void refill_energy(float energy)
        {
            this->energy += energy;
        }

        // Return points if ship get destroyed
        int get_damage(float damage)
        {
            this->hp -= damage;
            return check_hp();
        }
}