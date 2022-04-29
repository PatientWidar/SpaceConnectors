#include "GameObject.h"
#include<iostream>

bool GameObject::move()
{
    if(check_if_in_border(this->position.x + this->speed * this->direction[0], this->position.y + this->speed * this->direction[1]))
    {
        this->position.x += this->speed * this->direction[0];
        this->position.y += this->speed * this->direction[1];

        srcRect.x = 0;
        srcRect.y = 0;

        destRect.x = position.x;
        destRect.y = position.y;
        return false;
    }
    return true;
}

void GameObject::render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}