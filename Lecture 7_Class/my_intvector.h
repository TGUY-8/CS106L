
#define VEC_SIZE 10


class intvec{
    private:
    int* data ;
    int capacity;
    int* pointer;
    
    void resize();
    public:
    intvec();
    ~intvec();

    int get(int index);
    void push(int element);
    void clear();
    int* find(int element);
    int* begin_();
    int* end_();

};