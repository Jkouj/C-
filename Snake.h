//Snake.h

#include "Animal.h"

class Snake : public Animal{
    public:
        Snake(float initial_hunger) : Animal(initial_hunger,0.0){};
        void Speak() { std::cout << "Sssss!" << std::endl; }
};