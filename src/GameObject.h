#pragma once
#include "Point.h"
#include <string>
#include "SDL.h"
#include "TextureManager.h"

class GameObject
{
    protected:
        char direction[2];
        Point position;
        float speed;
        std::string color;
        float y_border;
        float x_border;
        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;
        int width;
        int height;
    
    public:
        bool move();
        void render();
        bool check_if_in_border(int x, int y)
        {
            return (y >= 0 && y <= y_border && x >= 0 && x <= x_border);
        }
        

        GameObject(
            Point position, 
            float speed, 
            std::string color,
            char direction[2],
            float y_border,
            float x_border,
            const char* texture,
            SDL_Renderer* renderer,
            int width,
            int height
            )
        {
            this->position = position;
            this->speed = speed;
            this->color = color;
            for(int i = 0; i < 2; i++)
                this->direction[i] = direction[i];
            this->y_border = y_border - height;
            this->x_border = x_border - width;
            this->renderer = renderer;
            objTexture = TextureManager::LoadTexture(texture, renderer);
            this->srcRect.h = height;
            this->srcRect.w = width;
            this->destRect.h = height;
            this->destRect.w = width;
            this->width = width;
            this->height = height;
        }
};