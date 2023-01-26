// Bird.h
#include "Animal.h"

class Bird : public Animal{
    public:
        Bird(float initial_hunger) : Animal(initial_hunger, 2.0){};
        void Speak() { std::cout << "Tweet tweet!" << std::endl; }
};