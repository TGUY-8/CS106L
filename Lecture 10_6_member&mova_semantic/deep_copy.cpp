#include <iostream>

class container{
    private:
    int* data;
    size_t capacity;
    //...

    public:
    container(size_t size);
    ~container();
    container(const container& other);
    container& operator = (const container& other);
};

container::container(size_t size)
: data{new int[size]}, capacity{size} {}

container::~container(){
    delete data;
}

container::container(const container& other)
: data{new int[other.capacity]} 
{
    for (size_t i = 0; i < other.capacity; i++)  data[i] = other.data[i];
}