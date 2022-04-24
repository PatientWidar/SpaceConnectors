#include "Point.h"
#include <string>

class GameObject
{
    private:
        Point position;
        float speed;
        //type model;
        string color;
        //pointer_to_object object
        char[2] direction;
        float y_border;
    
    public:
        void move();

        GameObject(
            Point position, 
            float speed, 
            //type model,
            string color,
            //pointer_to_object object,
            char[] direction,
            float y_border
            )
        {
            this->position = position;
            this->speed = speed;
            //this->model = model;
            this->color = color;
            //this->object = object;
            this->direction = direction;
            this->y_border = y_border;
        }
}