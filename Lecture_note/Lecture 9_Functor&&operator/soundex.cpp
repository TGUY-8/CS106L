#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

static char soundexEncode(char c){
    static const std::map<char, char> encoding = {
        {'A', '0'}, {'E', '0'}, {'I', '0'}, {'O', '0'}, {'U', '0'}, {'H', '0'}, {'W', '0'}, {'Y', '0'},
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    return encoding.at(std::toupper(c)); //a common pattern in C++ to write a lookup table to find values based on givin keys
}

static bool notZero(char c){
    return c != '0';
}

std::string soundex(const std::string& s)
{
    std::string letters;
    std::copy_if(s.begin(), s.end(), std::back_inserter(letters), ::isalpha); //std::back_inserter(container) creates an output iterator that allows dynamic resizing without requiring preallocation 

    char first_letter = letters[0];
    
    std::transform(letters.begin(), letters.end(), letters.begin(), soundexEncode);

    std::string unique;
    std::unique_copy(letters.begin(), letters.end(), unique.begin());
    
    unique[0] = std::toupper(first_letter);

    std::string no_zeros;
    std::copy_if(unique.begin(), unique.end(), std::back_inserter(no_zeros) , notZero);

    no_zeros += "0000";
    return no_zeros.substr(0, 4);

    return s;
}   