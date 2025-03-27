#include "class_version2.h"
#include <iostream>

StudentID::StudentID(std::string name, std::string sunet, int idNumber)
: name{name}, sunet{sunet}, idNumber(idNumber) {}

StudentID::StudentID()
: name{"Avery Wang"}, sunet{"jappleseed"}, idNumber{0000001} {}

StudentID::~StudentID(){
    std::cout << "Destructor is called" << std::endl;
}

int StudentID::getID(){
    return this->idNumber;
}

std::string StudentID::getname(){
    return this->name;
}

std::string StudentID::getsunet(){
    return this->sunet;
}

void StudentID::setID(int idNumber){
    this->idNumber = idNumber;
}

void StudentID::setName(std::string name){
    this->name = name;
}

void StudentID::setSunet(std::string sunet){
    this->sunet = sunet;
}