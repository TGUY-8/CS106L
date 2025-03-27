#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> v{1, 2, 3, 4, 5};
std::vector<double> v_d{1.1, 2.2, 3.3, 4.4, 5.5};

template <typename DT>
bool more_than_3(DT val){
    return val >= 3;
}

bool caseInsensitiveCompare(char a, char b){
    return std::tolower(a) == std::tolower(b);
}

void find(){
    auto it = std::find(v.begin(), v.end(), 3);
    if (it != v.end()) std::cout << "Found:" << *it << std::endl;
    else std::cout <<"Not found" << std::endl;
}

void find_if(){
    auto it = std::find_if(v.begin(), v.end(), more_than_3<int>); //the implicit interface ask for a unary predicate
    if (it != v.end()) std::cout << "Found:" << *it << std::endl;
    else std::cout <<"Not found" << std::endl;
}

//count , count_if the same

void for_each_1(){
    std::for_each(v.begin(), v.end(), [](int x){std::cout << x << std::endl;});
}

void for_each_2(){
    int sum = 0;
    std::for_each(v.begin(), v.end(), [&sum](int x){ sum += x;});
}

void equal(){
    std::string s1 = "What a day!";
    std::string s2 = "WHaT A dAy!";
    bool isEqual = std::equal(s1.begin(), s1.end(), s2.begin(), caseInsensitiveCompare);
}

void mismatch(){
    auto isClose = [](const auto& x, const auto& y) { return std::abs(a - b) <= 1};
    auto pair = std::mismatch(v.begin(), v.end(), v_d.begin(), isClose);
}

void search(){
    std::string haystack{"Hello, World!"};
    std::string needle{",world"};
    auto pointer = std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end(), caseInsensitiveCompare);
}

void search_n(){
    auto pointer = std::search_n(v.begin(), v.end(), v_d.begin(), v.end(), [](int x, int y){return std::abs(x - y) <= 1;});
}

