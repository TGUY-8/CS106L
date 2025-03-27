#include <iostream>

class Animal{
public:
    void eat();
    void wall();
};

class Dog : public Animal{
public:
    void talk() {std::cout << "Baoo" << std::endl;};
};

class Cat : public Animal{
public:
    void talk() {std::cout << "Miaooo" << std::endl;};
};

class Dinsaur : public Animal{
public:
    void talk() {std::cout << "Haaoooo" << std::endl;};
};

int main(){

    return 0;
}