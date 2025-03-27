#include <iostream> //`<>`without `.h` -> standerd libary header file,
                    //means the libary is one of the standerd libary built-in in C++ compile system
                    //<iostream> -> I/O class libary which allows you to use Stream object like `cout` or `cin`

//using namespace std;    

//What is noticeble is that all object from standerd libary header file is included in the namespace of std



int main()
{
    std::cout << "Welcome to C++!!" << std::endl;   // equivalent to std.cout() if in Python
    return 0;
}