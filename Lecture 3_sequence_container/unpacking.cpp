#include <iostream>

std::pair<int , int> FindPriceRange(int dist);

struct Discount
{
    double discoutFactor;
    int expirationDate;
    std::string nameOfDiscount;
};

int main()
{
    auto coupon = Discount{0.9 , 30 , "New Year"};
    auto  [factor , date , name] = coupon;
    std::cout << factor << date << name << std::endl;
    int dist = 100;
    auto [min , max] = FindPriceRange(dist);
    std::cout << min << max << std::endl;
    return 0;
}

std::pair<int , int> FindPriceRange(int dist)       //std::pair<type_name , type_name>
{
    int min = static_cast<int>(dist * 0.08 + 100);  //static_cast -> explicitly type conversion
    int max = static_cast<int>(dist * 0.36 + 750);
    return std::make_pair(min , max);
}