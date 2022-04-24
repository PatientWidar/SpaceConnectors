#include "GameObject.h"

void GameObject::move()
{
    this->position.x += this->speed * this->direction[0];
    this->position.y += this->speed * this->direction[1];
}