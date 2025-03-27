#include <iostream>
#include <vector>

template <typename T>
std::pair<T,T> my_minmax(T a, T b)
{
    return a > b ? std::pair<T, T>{b, a} :std::pair<T, T> {a, b};
}

template <typename input_iterator_begin, typename input_iterator_end, typename Datatype>
int count_occurences(input_iterator_begin begin, input_iterator_end end, Datatype val)
{
    int count = 0;
    for (const auto& i = begin; i != end; ++i)
    {
        if (*i == val) count++;
    }
    return count;
}


void test_template_explicitly(void);

int main()
{
    test_template_explicitly();
    
}


//Eplicit instantiation: specify the type T
void test_template_explicitly(void)
{
    auto [min1, max1] = my_minmax<double>(3.2, 4.5);
    std::cout << min1 << ',' << max1 << '\n';
    auto [min2, max2] = my_minmax<int>(2, 4);
    std::cout << min2 << ',' << max2 << '\n';
    auto [min3, max3] = my_minmax<std::string>("Avery", "Anna");
    std::cout << min3 << ',' << max3 << '\n';
    auto [min4, max4] = my_minmax<double>(2, 2.3);
    std::cout << min4 << ',' << max4 << '\n';
    auto [min5, max5] = my_minmax<std::vector<int>>({3, 4}, {4, 3});
}