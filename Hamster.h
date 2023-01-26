// Hamster.h
#include "Animal.h"

class Hamster : public Animal{
    public:
        Hamster(float initial_hunger) : Animal(initial_hunger, 4.0){};
        void Speak() { std::cout << "Hammy Wammy" << std::endl; }
};