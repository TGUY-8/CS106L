#include <iostream>
#include <vector>
#include <map>


std::vector<int> vec_1{2, 3, 4, 7, 6};
std::vector<int> vec_2{2, 3, 4, 5, 3};

std::vector<std::string> vec_3{"Avery", "Wang"};
std::vector<std::string> vec_4{"Avery", "Wang"};

std::map<std::string, double> map_1{{"C", 10}, {"C++", 100}, {"Python", 1000}};
std::map<std::string, double> map_2{{"C", 10}, {"C++", 100}, {"Java", 11}};

std::tuple<bool, int, int> mismatch_narrow(const std::vector<int>& vec1, const std::vector<int>& vec2)
{
    size_t i = 0;
    while (i < vec1.size() && vec1[i] == vec2[i])
    {
        ++i;
    }
    if (i == vec1.size()) return {true, 0, 0};
    else return {false, vec1[i], vec2[i]};
}


template <typename Collection, typename DataType>
std::tuple<bool, DataType, DataType> mismatch_Generic(const Collection colle_1 , const Collection colle_2)
{
    auto i = colle_1.begin();
    auto j = colle_2.begin(); 
    while (*i == *j)
    {
    ++i, ++j; 
    }
    if (i == colle_1.end()) return {true, 0, 0};
    else return {false, *i, *j};
}


template <typename T>
void cout_Tuple(std::tuple<bool, T , T> arg)
{
    auto [boolean, num1, num2] = arg;
    std::cout << boolean << ' ' << num1 << ' ' << num2 << std::endl;
}


int main()
{
    std::tuple<bool, int , int> tuple_1 = mismatch_narrow(vec_1, vec_2);
    std::tuple<bool, int , int> tuple_2 = mismatch_Generic<std::vector<int>, int>(vec_1, vec_2);
    cout_Tuple<int>(tuple_1);
    cout_Tuple<int>(tuple_2);
    
    std::tuple<bool, std::string , std::string> tuple_3 = mismatch_Generic<std::vector<std::string>, std::string>(vec_3, vec_4);
    //cout_Tuple<std::string>(tuple_3);

    //std::tuple<bool, std::pair<std::string, double>, std::pair<std::string, double>> tuple_4= mismatch_Generic<std::map<std::string, double>, std::pair<std::string, double>>(map_1, map_2);
    //cout_Tuple(tuple_4);

    return 0;
}