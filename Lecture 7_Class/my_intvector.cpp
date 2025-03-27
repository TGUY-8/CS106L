#include <iostream>
#include "my_intvector.h"

intvec::intvec()
: data{new int[VEC_SIZE]}, capacity{VEC_SIZE}, pointer{&data[0]}  {}

intvec::~intvec(){
    delete[] this->data;

}

int intvec::get(int index){
    if (index >= VEC_SIZE) throw "over the bound!";
    return data[index];
}

int* intvec::begin_()
{
    return &data[0];
}

int* intvec::end_(){
    return &data[VEC_SIZE];
}

void intvec::push(int element){
    *pointer = element;
    ++pointer;
}

void intvec::clear(){
    *pointer = 0;
    do
    {
        --pointer;
        *pointer = 0;
    } while (pointer != data);
}

int* intvec::find(int element){
    int* temp_pointer = pointer; //const int* 表示所指对象不能被改变
    for (; temp_pointer >= data; --temp_pointer)
    {
        if(*temp_pointer == element) return temp_pointer;
    }
    return nullptr;
}

int main()
{
    intvec my_vec = {};
    my_vec.push(3);
    my_vec.push(4);
    my_vec.push(6);
    auto element = my_vec.begin_();
    std::cout << *element << std::endl;
    auto re = my_vec.find(3);
    std::cout << re << std::endl;
    my_vec.clear();
    std::cout << *element << std::endl;
    
    return 0;
}