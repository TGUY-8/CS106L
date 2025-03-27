#include <iostream>
#include <vector>


void BubbleSort(std::vector<int>& v);

int main()
{
    std::vector<int> vec(20);
    for (size_t i = 0; i < vec.size(); i++)  //get total num of elements in container
    {
        vec[i] = rand(); //rand() -> generate a random number
    }
    
    BubbleSort(vec);

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
    

    return 0;
}

void BubbleSort(std::vector<int>& v)
{
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        for (size_t j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j+1])
            {
                int temp = v[ j ];
                v[j] = v[ j + 1 ];
                v[j + 1] = temp;
            }
        }
    }
}


