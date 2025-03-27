#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

struct Time
{
    int h;
    int min;
};

struct Course{
    std::string code;
    Time startTime; Time endTime;
    std::vector<std::string> instructor;
};

int main()
{
    Course CS{"CS106L" , {15 , 30} , {16 , 30} , {"Wang" , "Zeng"}};     //uniform initialization 
    auto [id , s , e , teachers] = CS;
    auto time = std::make_pair(s , e);
    std::cout << id << '\n' << s.h << s.min <<e.h << e.min << std::endl ;
    return 0;
}