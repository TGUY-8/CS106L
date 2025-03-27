//A functor is any object that defines an operator()
//since a functor is an object, it can have state

struct my_functor{
    int value;
    int operator() (const int a) const{return a * value;} ;
};

//my_functor f;
//f.value = 6;
//f(3); //18

//one tricy truth -> lambda is actually implement by functor
int main(){
    int N{0};
    auto islessThanN = [N] (int x) {return x < N;};
    //this line is actually equal to the following:

    // class __lambda_6_18
    // {
    //     private:
    //     int N;

    //     public:
    //     inline bool operator() (int x) {return x < N;};
    //     __lambda_6_18(int& N) 
    //     : N{N} {}
    // };
    // __lambda_6_18 lessThanN = __lambda_6_18{N};
    

    return 0;
}