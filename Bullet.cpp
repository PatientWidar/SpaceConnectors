#include "Bullet.h"


Bullet::Bullet(
    Point position, 
    float speed, 
    //type model,
    string color,
    //pointer_to_object object,
    char[] direction,
    float y_border,
    float damage

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
    this->damage = damage;
}