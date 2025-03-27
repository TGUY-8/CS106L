#include "intvec.h"
#include <stdexcept>

IntVector::IntVector()
: track{0}, _capacity{4}, _data{new int[_capacity]} {}

IntVector::~IntVector(){
    delete[] _data;
}

void IntVector::resize(){
    _capacity *= 2;
    int* newVec = new int[_capacity];
    for (size_t i = 0; i < this-> track; i++)
    {
        newVec[i] = _data[i];
    }
    delete[] _data;
    _data = newVec;
}

void IntVector::push_back(const int& value){
    if (track == _capacity) resize();
    _data[track] = value;
    ++track;
}

int& IntVector::at(size_t index){
    if (index < 0 || index >= _capacity) throw "out of range";
    else return _data[index];
}

size_t IntVector::size(){
    return track;
}

bool IntVector::empty(){
    return track == 0;
}

IntVector::iterator IntVector::begin(){
    return _data;
}

IntVector::iterator IntVector::end(){
    return _data + track;
}