//the type of the args doesn't have to be the same
//the instantiation of the template done at compile - time (before run - time) , the compiler will automatically overload for u
#include <iostream>

template <typename T>
T my_min(const T& val){
    return val;
}

template <typename T, typename... Args>
T my_min(const T& val, const Args&... args){
    auto m = my_min(...args);
    return val < m ? val : m;
}


void format(const std::string& base){
    std::cout << base;
}

template <typename T, typename ...Args>
void format(std::string& base, const T val, const Args... args){
    auto block = base.find("{}");
    if (block == std::string::npos) throw std::runtime_error("Extra arg");
    std::cout << base.substr(0, block);
    std::cout << val;
    format(base.substr(block + 2), args...);
}

void format_(const std::string& base){
    std::cout << base;
}

template <typename T , typename... Args>
void format_(const std::string& base, const T val, const Args... args){
    auto pos = base.find("{}");
    if (pos == std::string::npos) throw std::runtime_error("Extra arg");
    std::cout << base.substr(0, pos) << val;
    format_(base.substr())
}