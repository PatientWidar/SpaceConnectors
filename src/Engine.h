#pragma once
#include "Bullet.h"
#include "SpaceShip.h"
#include "Highscore.h"
#include <vector>
#include <string>
#include "SDL.h"
#include <random>

class Engine
{
    private:
        std::vector<Bullet> bullets;
        std::vector<SpaceShip> spaceShips;
        SpaceShip *player;
        char directions[3][2];
        int score;
        std::string nick;
        float refresh_rate;
        float speed;
        float width;
        float height;
        bool fullscreen;
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
        int enemyTimer;
        int enemySpawnSpeed;


    public:
        Engine(
            std::string nick,
            float refresh_rate
        );
        Engine()
        {
            //Setting up directions in which way friendly bullets and enemy ships would move
            //Enemy Bullet
            this->directions[0][0] = 0;
            this->directions[0][1] = 1;
            //SpaceShip
            this->directions[1][0] = 0;
            this->directions[1][1] = 0;
            //Friendly Bullet
            this->directions[2][0] = 0;
            this->directions[2][1] = -1;
            this->score = 0;
            this->nick = "-";
            this->refresh_rate = 60;
            this->isRunning = true;
            this->fullscreen = false;
            this->speed = 1;
            this->enemyTimer = 0;
            this->enemySpawnSpeed = 180;
        }
        void start();
        void start(int width, int height);
        void update();
        void handleEvents();
        void end();
        bool running()
        {
            return isRunning;
        }
        Bullet createFriendlyBullet(Point position, float damage)
        {
            return Bullet(position, speed, "any", directions[2], height, width, damage, "graphic/friendlyBullet.png", renderer, 7, 10, false);
        }
        Bullet createEnemyBullet(Point position, float damage)
        {
            return Bullet(position, speed, "any", directions[0], height, width, damage, "graphic/enemyBullet.png", renderer, 7, 10, true);
        }
        SpaceShip createEnemy(int score, int hp)
        {
            int outputx = 0 + (rand() % static_cast<int>(767 + 1));
            int outputy = 0 + (rand() % static_cast<int>(360 + 1));
            Point newPoint(outputx, outputy);
            return SpaceShip(newPoint, speed, "any", directions[1], height, width, 0.6, 1, hp, score, "graphic/enemy.png", renderer);
        }
        void render();
        Highscore get_highscore();
};