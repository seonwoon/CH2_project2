#include <iostream>
#include <cstdlib>
#include <ctime>

// Base class Animal
class Animal {
public:
    virtual void makeSound() const = 0; // Pure virtual function
    virtual ~Animal() = default; // Virtual destructor
};

// Derived class Dog
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

// Derived class Cow
class Cow : public Animal {
public:
    void makeSound() const override {
        std::cout << "Moo!" << std::endl;
    }
};

// Zoo class
class Zoo {
private:
    Animal* animals[10] = { nullptr }; // Array of Animal pointers
    int count = 0; // Number of animals added

public:
    // Add an animal to the zoo
    void addAnimal(Animal* animal) {
        if (count < 10) {
            animals[count++] = animal;
        }
        else {
            std::cout << "Zoo is full!" << std::endl;
        }
    }

    // Perform actions for all animals in the zoo
    void performActions() {
        for (int i = 0; i < count; ++i) {
            if (animals[i]) {
                animals[i]->makeSound();
            }
        }
    }

    // Destructor to clean up dynamically allocated animals
    ~Zoo() {
        for (int i = 0; i < count; ++i) {
            delete animals[i];
        }
    }
};

// Function to create a random animal
Animal* createRandomAnimal() {
    int randomNum = std::rand() % 3; // Generate a random number (0, 1, or 2)
    switch (randomNum) {
    case 0: return new Dog();
    case 1: return new Cat();
    case 2: return new Cow();
    default: return nullptr; // This should never happen
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

    // Create an array of Animal pointers
    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Cow();

    // Print sounds of all animals
    for (int i = 0; i < 3; ++i) {
        animals[i]->makeSound();
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < 3; ++i) {
        delete animals[i];
    }

    // Demonstrate Zoo functionality
    Zoo myZoo;
    for (int i = 0; i < 5; ++i) {
        myZoo.addAnimal(createRandomAnimal());
    }

    std::cout << "Animals in the zoo are making sounds:" << std::endl;
    myZoo.performActions();

    return 0;
}
