#include "SpaceShip.h"
#include<iostream>


SpaceShip::SpaceShip(
    Point position, 
    float speed, 
    std::string color,
    char direction[2],
    float y_border,
    float x_border,
    float shot_energy,
    float start_energy,
    float HP,
    int score,
    const char* texture,
    SDL_Renderer* ren
) : GameObject(
    position, 
    speed, 
    color,
    direction,
    y_border,
    x_border,
    texture,
    ren,
    30,
    20
)
{
    this->shot_energy = shot_energy;
    this->energy = start_energy;
    this->hp = HP;
    this->score = score;
}

Point SpaceShip::shot()
{
    if(energy >= shot_energy)
    {
        //generate Point(for bullet) at space position + over sth
        energy = 0;
        return Point(position.x + 15, position.y);
    }
    return Point(0, 0);
}

int SpaceShip::check_hp()
{
    if(hp > 0)
        return 0;
    
    //destroy SpaceShip when hp <= 0
    
    // Return points gotten from destroying ship
    return score;
}