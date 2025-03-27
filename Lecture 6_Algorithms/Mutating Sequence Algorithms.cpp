#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
std::vector<std::string> v_s{"apple", "banana", "cherry"};



void copy(){
    std::vector<int> v_(v.size());
    auto end = std::copy(v.begin(), v.end(), v_.begin());
}

void copy_if(){
    std::vector<std::string> v_s_;
    auto check_b = [](std::string& str) {return str[0] == 'b';};
    auto end = std::copy_if(v_s.begin(), v_s.end(), v_s_.begin(), check_b);
}

void replace(){
    std::replace(v.begin(), v.end(), -1 , 1);
}

void replace_if(){
    std::replace_if(v.begin(), v.end(), [](int x) {return x > 3;}, 2);
}

void swap(){
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{5, 4, 3, 2, 1};
    std::swap(v1, v2);
}

void swap_ranges(){
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2{5, 4, 3, 2, 1};
    std::swap_ranges(v1.begin(), v1.begin() + 3 , v2.begin());
}

void reverse(){
    std::string str = "!olleh";
    std::reverse(str.begin(), str.end());
    std::cout << str << std::endl; // hello!
}

void rotate(){
    std::string str = "llohe";
    std::rotate(str.begin(), str.begin() + 3, str.end());
}

void remove(){
    std::vector<int> vec = {1, 2, 3, 4, 2};
    auto new_end = std::remove(vec.begin(), vec.end(), 2);
    vec.erase(new_end, vec.end());
}

void remove_if(){
    std::vector<int> vec(v.size());
    auto new_end = std::remove_if(vec.begin(), vec.end(), [](int x) {return x % 2 == 0;});
    vec.erase(new_end , vec.end());
}

void unique(){
    std::vector<int> vec{1, 1, 2, 2, 3, 3, 4, 4, 5};
    auto new_end = std::unique(vec.begin(), vec.end());
    vec.erase(new_end, vec.end());
}

void unique_copy(){
    std::vector<int> vec(v.size());
    auto isClose = [](auto x, auto y){return abs(x - y) <= 1;};
    auto vec_end = std::unique(v.begin(), v.end(), vec.begin());
}