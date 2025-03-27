#include <iostream>
#include <algorithm>

#define DEFAULT_SIZE 5
#define EMPTY 0

class User{
    private:
    size_t size;
    size_t capacity;
    std::string* friends;
    std::string name;

    public:
    User(std::string& name);
    ~User();
    User(const User& other);
    User& operator = (const User& other);

    User(User&& other);
    User& operator = (User&& rhs);

    void add_friend(const std::string& _friend);
    std::string getname() const;
    friend std::ostream& operator << (std::ostream& os, const User& rhs);
    friend bool operator < (const User& lhs, const User& rhs);
    
};