// main.cpp
#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Snake.h"
#include "Hamster.h"

int main(int argc, char*argv[]){

    int number_of_animals = std::stoi(argv[1]);
    Animal** arr = new Animal*[number_of_animals];

    for (int i = 0; i < number_of_animals; i++){
        int x = std::stoi(argv[i+2]);

        std::string animal_name;
        std::cin >> animal_name;

        if (animal_name == "Cat"){
            Cat* cat = new Cat(x);
            arr[i] = cat;
        }
        else if (animal_name == "Dog"){
            Dog* dog = new Dog(x);
            arr[i] = dog;
        }
        else if (animal_name == "Bird"){
            Bird* bird = new Bird(x);
            arr[i] = bird;
        }
        else if (animal_name == "Snake"){
            Snake* snake = new Snake(x);
            arr[i] = snake;
        }
        else if (animal_name == "Hamster"){
            Hamster* hamster = new Hamster(x);
            arr[i] = hamster;
        }
        //std::cout << animal_name;
    }
                        //arr.length
    for (int i = 0; i < number_of_animals ; i++) {
        arr[i]->Speak();
        std::cout << arr[i]->GetHunger() << std::endl;
    }

    // Cat cat1(50);	// object constructed during compile-time
    // Dog* dog1 = new Dog(40);	// object constructed during run-time. 'dog1' is a pointer.

    // std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
    // // The long-form version would be '(*dog1).GetHunger()' and yes, that set of '()' is required.
    // std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;

    // cat1.Eat(10);
    // dog1->Eat(40);

    // std::cout << "Cat hunger: " << cat1.GetHunger() << std::endl;
    // std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;

    // std::cout << "Cat legs: " << cat1.GetLegs() << std::endl;

    // cat1.Speak();
    // dog1->Speak();
}