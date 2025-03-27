#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#define SIZE 20

int main()
{
    std::vector<int> vec(SIZE);
    std::generate(vec.begin() , vec.end() , rand);
    std::sort(vec.begin() , vec.end());
    std::copy(vec.begin() , vec.end() , std::ostream_iterator<int>(std::cout , "\n"));
    return 0;
}