#pragma once
#include "Engine.h"
#include "SDL.h"
#include<iostream>
#include "SpaceShip.h"

Engine::Engine(
    std::string nick,
    float refresh_rate
)
{
    Engine();
    this->nick = nick;
    this->refresh_rate = refresh_rate;
    this->width = 800;
    this->height = 600;
}

void Engine::start()
{
    Engine::start(800, 600);
    player = new SpaceShip(Point(10, 500), speed, "red", directions[1], 600, 800, 0.6, 20, 1000.0, 0, "graphic/player.png", renderer);
}

void Engine::start(int width, int height)
{
    this->width = width;
    this->height = height;
    score = 0;
    int flags = 0;
    if(fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow("Space Connectors", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if(window)
        {
            //okno stworzone
        }
        else
        {
            //okno nie stworzone
            isRunning = false;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            //renderer stworzony
        }
        else
        {
            //renderer nie stworzony
            isRunning = false;
        }
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Engine::update()
{
    std::cout<<"Ship hp: "<<player->get_hp()<<std::endl;
    if(enemyTimer >= enemySpawnSpeed)
    {
        enemyTimer -= enemySpawnSpeed;
        spaceShips.insert(spaceShips.end(), createEnemy(130, 40));
    }
    enemyTimer++;
    player->move();

    for(int i = bullets.size() - 1; i >= 0 ; i--)
    {
        int temp_score = 0;
        if(bullets.at(i).isEnemy() == false)
            for(int j = spaceShips.size() - 1; j > 0; j--)
            {
                temp_score += bullets.at(i).deal_damage(spaceShips.at(j));
                if(temp_score > 0)
                {
                    score += temp_score;
                    spaceShips.erase(spaceShips.begin() + j);
                    bullets.erase(bullets.begin() + i);
                    break;
                }
            }
        else
        {
            std::cout<<"Ship hp: "<<player->get_hp()<<std::endl;
            float temp_hp = player->get_hp();
            bullets.at(i).deal_damage(*player);
            if(player->get_hp() <= 0)
            {
                isRunning = false;
                break;
            }
            if(temp_hp != player->get_hp())
            {
                bullets.erase(bullets.begin() + i);
                continue;
            }
        }
        if(temp_score > 0)
        {
            continue;
        }
        if(bullets.at(i).move())
        {
            bullets.erase(bullets.begin() + i);
        }
    }

    for(int i = 0; i < spaceShips.size(); i++)
    {
        spaceShips.at(i).move();
        spaceShips.at(i).refill_energy(0.003);
        Point newBulletPosition;
        newBulletPosition = spaceShips.at(i).shot();
        if(newBulletPosition.x != 0 && newBulletPosition.y != 0)
        {
            bullets.insert(bullets.end(), createEnemyBullet(newBulletPosition, 10));
        }
    }

    player->refill_energy(0.003);

}

void Engine::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    char temp_directions[2];
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                isRunning = false;
            }
            if(event.key.keysym.sym == SDLK_a)
            {
                temp_directions[0] = -1;
                temp_directions[1] = 0;
                player->change_dir(temp_directions);
            }
            else if(event.key.keysym.sym == SDLK_d)
            {
                temp_directions[0] = 1;
                temp_directions[1] = 0;
                player->change_dir(temp_directions);
            }
            if(event.key.keysym.sym == SDLK_a && event.key.keysym.sym == SDLK_d)
            {
                temp_directions[0] = 0;
                temp_directions[1] = 0;
                player->change_dir(temp_directions);
            }
            if(event.key.keysym.sym == SDLK_SPACE)
            {
                Point newBulletPosition;
                newBulletPosition = player->shot();
                if(newBulletPosition.x != 0 && newBulletPosition.y != 0)
                {
                    bullets.insert(bullets.end(), createFriendlyBullet(newBulletPosition, 10));
                }
            }
            break;

        case SDL_KEYUP:
            temp_directions[0] = 0;
            temp_directions[1] = 0;
            if(event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d)
                player->change_dir(temp_directions);
            break;
        
        default:
            break;
    }
}

void Engine::render()
{
    SDL_RenderClear(renderer);
    player->render();
    for(int i = 0; i < bullets.size(); i++)
    {
        bullets.at(i).render();
    }
    for(int i = 0; i < spaceShips.size(); i++)
    {
        spaceShips.at(i).render();
    }

    SDL_RenderPresent(renderer);
}

void Engine::end()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

Highscore Engine::get_highscore()
{
    return Highscore(nick, score);
}