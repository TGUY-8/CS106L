#include <iostream>
#include <sstream>
#include <map>

int main()
{
    std::cout << "Enter sth." << std::endl;
    std::string response;

    std::map<std::string , int> frequency;

    while (true)
    {
        getline(std::cin , response);
        if (response.empty()) break;
        std::istringstream iss(response);std::string token;
        while (iss >> token)
        {
            frequency[token]++;  //key statement - if the element in map return its value else add the key to it and set the value by default 
        }
    }

    std::cout << "Enter certain word" << std::endl;
    std::string check;
    while (true)
    {
        getline(std::cin , check);
        if (check.empty()) break;
        if (frequency.count(check)) std::cout << check <<':'<< frequency[check] << std::endl;
        else std::cout << "None" << std::endl;
    }
    return 0;
}