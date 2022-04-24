#include "SpaceShip.h"


SpaceShip::SpaceShip(
    Point position, 
    float speed, 
    //type model,
    string color,
    //pointer_to_object object,
    char[] direction,
    float y_border,
    float shot_energy,
    float start_energy
    float hp,
    int score
) : GameObject(
    position, 
    speed, 
    //model,
    color,
    //object,
    direction,
    y_border
)
{
    this->shot_energy = shot_energy;
    this->energy = start_energy;
    this->hp = hp;
    this->score = score;
}

Bullet SpaceShip::shot()
{
    if(energy >= shot_energy)
    {
        //generate Bullet at space position + over sth
        energy = 0;
    }
}

int SpaceShip::check_hp()
{
    if(hp > 0)
        return 0;
    
    //destroy SpaceShip when hp <= 0
    
    // Return points gotten from destroying ship
    return score;
}