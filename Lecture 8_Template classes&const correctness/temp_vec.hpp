#pragma once
#include <iostream>

#define DEFAULT_SPACE 1

template <typename T>
class vector_{
    private:
    size_t capacity;
    T* data;
    size_t size;

    void resize();
    public:
    vector_();
    ~vector_();

    T& at(const size_t index) const;  //const promise to the compiler that this method won't change objecy's property so that you can apply this method to a const instance
    size_t size() const;
    bool empty() const;

    void push_back(T val);

    T* begin();
    T* end();


};

template <typename T>
vector_<T>::vector_()
: capacity{DEFAULT_SPACE}, data{new T[DEFAULT_SPACE]}, size{0} {}

template <typename T>
vector_<T>::~vector_(){
    delete[] data;    
}

template <typename T>
T& vector_<T>::at(const size_t index) const { return data[index];}

template <typename T>
size_t vector_<T>::size() const { return this->size;}

template <typename T>
bool vector_<T>::empty() const { return size == 0;}

template <typename T>
void vector_<T>::resize(){
    this->capacity *= 2;
    T* ori_data = data;
    data = new T[capacity];
    for (size_t i = 0; i < this->size; i++)
    {
        data[i] = ori_data[i];
    }
    delete[] ori_data;
}

template <typename T>
void vector_<T>::push_back(T val){
    if(this->size == this->capacity) resize();
    ++size;
    this->data[size] = val;
}

