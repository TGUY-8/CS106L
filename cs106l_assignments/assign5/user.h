/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */

   
   User(const User& other): _name(other._name), _friends(new std::string[other._capacity]), _size(other._size), _capacity(other._capacity)
   {
    std::copy(other._friends, other._friends + other._size, _friends);
   }


   User& operator = (const User& other)
   { 
      if(this != &other ){
        delete [] _friends;
        _name = other._name;
        _size = other._size;
        _capacity = other._capacity;
        _friends = new std::string[_capacity];
      
       std::copy(other._friends, other._friends + _size , _friends);
      }
      return *this;
  }


   friend std::ostream& operator << (std::ostream& os, User list) //std::ostream can't directly create an instance , so use by refrence
   {
    os << "User(name=" << list.get_name() << ", friends=[";
    for (size_t i = 0; i < list._size ; i++) os << (i ? ", " : "") << list._friends[i];
    os << "])";

    return os;
   }

   ~User(){
  delete[] this->_friends; 
   }

   User& operator += (User& other)
   {
    add_friend(other.get_name());
    other.add_friend(this->get_name());
    return *this;
   }

   bool operator < (const User& rhs) const{
  return _name < rhs._name;
   }

   User(const User&& other) = delete;
   User& operator = (const User&& other) = delete;

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};



