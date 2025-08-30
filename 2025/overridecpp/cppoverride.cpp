#include <iostream>
#include <string>
class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const {
        std::cout << "Some animal sound" << std::endl;
    }
    virtual std::string getType() const {
        return "Animal";
    }
    void breathe() {
        std::cout << "Breathing..." << std::endl;
    }
};
class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
    std::string getType() const override {
        return "Dog";
    }
    // ERROR: This would cause compilation error with override
    // void makeSound() override { } // Missing const qualifier
    // int getType() override { return 0; } // Wrong return type
};
class Cat : public Animal {
public:
    void makeSound() const {
        std::cout << "Meow!" << std::endl;
    }
    void MakeSound() const {
        std::cout << "Wrong sound!" << std::endl;
    }
};
class Bird : public Animal {
public:
    void makeSound() const override {
        std::cout << "Chirp! Chirp!" << std::endl;
    }
};
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual std::string getName() const {
        return "Shape";
    }
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
    std::string getName() const override {
        return "Circle";
    }
};
int main() {
    Dog dog;
    dog.makeSound();
    std::cout << "Type: " << dog.getType() << std::endl;
    Animal* animal = new Dog();
    animal->makeSound();
    delete animal;
    Cat cat;
    Animal* animalCat = &cat;
    animalCat->makeSound();
    Circle circle(5.0);
    std::cout << "Circle area: " << circle.area() << std::endl;
    std::cout << "Name: " << circle.getName() << std::endl;
    return 0;
}
