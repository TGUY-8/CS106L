#include <iostream>
#include <vector>

template <typename T>
void PrintInt(const T x){
    std::cout << x << std::endl;
}

template <typename Collection, typename ret, typename T>
void for_each(Collection& box, ret(*func)(const T)){
    for(const auto& elem : box){
        func(elem);
    }
}

int main(){
    std::vector<int> v{1, 2, 3, 4, 5};
    for_each<std::vector<int> , void , int>(v, PrintInt<int>);
    //you can assign function to viariable
    void(*print_)(const int) = PrintInt;
    return 0;
}

