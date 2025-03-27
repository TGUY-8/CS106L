//const-correctness
//When passing variable as perameter , for safety consideration, non-const to const is allowed but const to non-const is unacceptable , that's why there's need to explicitly declare 'const'
//you should always follow:
//1)ues const as long as it logically applies 
//2)overload member functions for const and non-const access (eg. .at(index) : instance is const -> method is read=only , instance is mutable -> return value is mutable)



#define DEFAULT 4

template <typename T>
class Vector{
    private:
    size_t capacity;
    size_t size;
    T* data;

    void resize();

    public:
    using iterator = T*;

    Vector();
    ~Vector();

    void push_back(const T& val) const;

    T& at(size_t index);
    const T& at(size_t index) const;

    T& find(const T& value);
    const T& find(const T& value) const;

    T& operator[] (size_t index);

    iterator begin();
    iterator end();
};

template <typename T>
Vector<T>::Vector()
:capacity{DEFAULT}, size{ 0 } , data{new T[DEFAULT]} {}

template <typename T>
Vector<T>::~Vector(){
    delete[] data;
}

template <typename T>
void Vector<T>::resize(){
    capacity *= 2;
    auto ori_data = data;
    data = new T[capacity];
    for (size_t i = 0; i < size; i++)
    {
        data[i] = ori_data[i];
    }
    delete[] ori_data;
}

template <typename T>
T& Vector<T>::at(size_t index) {return data[index];}

template <typename T>
const T& Vector<T>::at(size_t index) const {return data[index];}

template <typename T>
T& Vector<T>::operator[] (size_t index){return data[index];}

template <typename T>
Vector<T>::iterator Vector<T>::begin() {return data;}

template <typename T>
Vector<T>::iterator Vector<T>::end() {return data + size;}

//const itarator is a little bit tricky
//const Vector<int>::iterator itr -> pointer points one place only
//Vector<int>::const_itarator itr -> read-only