// Animal.cpp
#include "Animal.h"

Animal::Animal(float initial_hunger, float initial_legs){
    this->hunger = initial_hunger;
    this->legs = initial_legs;
}

float Animal::GetHunger(){
    return this->hunger;
}

float Animal::GetLegs(){
    return this->legs;
}

void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}
