#include "Bullet.h"

Bullet::Bullet(
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

) : GameObject(
    position, 
    speed, 
    color,
    direction,
    y_border,
    x_border,
    texture,
    ren,
    width,
    height
)
{
    this->damage = damage;
    this->enemy = enemy;
}