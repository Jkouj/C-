// Animal.h
#pragma once
#include <iostream>

class Animal{
    private:
    	float hunger;
        float legs;
    public:
      Animal(float initial_hunger, float initial_legs);
    	void Eat(float sustenance);
    	float GetHunger();
        float GetLegs();
    	virtual void Speak() = 0;
};