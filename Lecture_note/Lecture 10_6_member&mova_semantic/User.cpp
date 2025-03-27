#include "User.h"

User::User(std::string& name)
: size{EMPTY}, capacity{DEFAULT_SIZE}, name{name}, friends{new std::string[DEFAULT_SIZE]}  {}

User::~User()
{
    delete[] friends;
}

User::User(const User& other)
: size{other.size}, capacity{other.capacity}, friends{new std::string[capacity]}, name{other.name}
{
    std::copy(other.friends, other.friends + size, friends);
}

User& User::operator = (const User& other)    
{
    if (this != &other)
    {
        name = std::move(other.name);
        size = other.size;
        capacity = other.capacity;
        delete[] friends;
        friends = new std::string[capacity];

        std::copy(other.friends, other.friends + size , friends);
    }
}

User::User(User&& other)
: name{std::move(other.name)}, size{other.size}, capacity{other.capacity}, friends{other.friends} { other.friends = nullptr;}

User& User::operator = (User&& rhs){
    name = rhs.name;
    size = rhs.size;
    capacity = rhs.capacity;
    friends = rhs.friends;

    rhs.friends = nullptr;
    
    return *this;
}


std::string User::getname() const {
    return name;
}

void User::add_friend(const std::string& _friend){
    if (size == capacity)
    {
        capacity = capacity*2+1;
        auto ori = friends;
        friends = new std::string[capacity];
        
        std::copy(ori, ori + size, friends);
        delete[] ori;
    }
    friends[size++] = _friend;
}


std::ostream& operator << (std::ostream& os, const User& rhs){
    os << rhs.name << '\n';
    for (size_t i = 0; i < rhs.size; i++) os << rhs.friends[i] << (i == rhs.size -1 ? "" : ", ");
    return os;
}

bool operator < (const User& lhs, const User& rhs){
    return lhs.name < rhs.name;
}


int main(){
    std::string name;
    std::string _friend;
    std::cin >> name;
    std::cin >> _friend;
    User u{name};
    u.add_friend(_friend);
    std::cout << u;

    return 0;
}

