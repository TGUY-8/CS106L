#include <iostream>
#include <vector>

//common pattern in C++ for operator-overload

class StudentIdCard{
    private:
    size_t id_number;
    std::string name;
    
    public:
    StudentIdCard(std::string name, std::string id);
    ~StudentIdCard();
    
    friend bool operator < (const StudentIdCard& s1, const StudentIdCard& s2);

};

bool operator < (const StudentIdCard& s1, const StudentIdCard& s2){
    return s1.id_number < s2.id_number;
}

