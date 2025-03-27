#include <iostream>
#include <vector>

template <typename InputIterator, typename Predicate>
int count_satisfied(InputIterator begin, InputIterator end, Predicate pre){
    int count = 0;
    for(auto iter = begin; iter != end ; ++iter){
        if(pre(*iter)) count++;
    }
    return count;
}

//so a predicate is actually just a function with a boolean return
bool isLessThan5(int val){
    return val <= 5;
}

//you can even use template to define a predicate
template <typename Type>
bool isLessThan4(Type val){
    return val <= 4;
}

int main()
{
    std::vector<int> vec_1{1, 2, 5, 7, 8};
    int num_1 = count_satisfied(vec_1.begin(), vec_1.end(), isLessThan5);
    int num_2 = count_satisfied(vec_1.begin(), vec_1.end(), isLessThan4<int>);
    std::cout << num_1 << '\n' << num_2 << '\n';

    //Q: we've done duplicate work to implement these two functions because the interface count function provided could only take one parameter , how to fix that? -》 lambda
    int limit = 3;
    auto isLessThan = [limit](auto val) {return val <= limit;};  //inside the [] is the capture list, allow you to access varibles in other scope(copy by default , and you can also pass it by reference)
    int num_3 = count_satisfied(vec_1.begin(), vec_1.end(), isLessThan);
    std::cout << num_3 <<std::endl;

    return 0;
}