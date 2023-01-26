// Dog.h
#include "Animal.h"

class Dog : public Animal{
    public:
        Dog(float initial_hunger) : Animal(initial_hunger, 4.0){};
        void Speak() { std::cout << "Woof!" << std::endl; }
};