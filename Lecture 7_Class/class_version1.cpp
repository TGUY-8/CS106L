#include <sstream>
#include <iostream>

#define COMMON_BUT_NOT_RECOMMENDED 0

class StudentID
{
    private:
    std::string name;
    std::string sunet;
    int idNumber;
    public:

#if COMMON_BUT_NOT_RECOMMENDED:
    StudentID(std::string name, std::string sunet, int idNumber){
        this->name = name;      //initialization list -> directly initialize to the value you assign
        this->sunet = sunet;    //construct function -> for C++ type(string , vector), first invoke its default constructor and the execute the assignment which leads to extra cost
        this->idNumeber = idNumber;     //`this` is a pointer point to present instance
    }
#else:

    //Constructor 
    //-> When using initialization list , use colon instead of brace curly, and use comma to seperate each parameter. The single {} represent the body of the function
    StudentID(std::string name, std::string sunet, int idNumber)
    : name{name} , sunet{sunet}, idNumber{idNumber}  {}
    //reload a default version(the compiler know which one to choose depend on the argument)
    StudentID()
    :   name{"John Appleseed"}, sunet{"jappleseed"}, idNumber{0000001} {}

    //Deconstructor
    ~StudentID()
    {
        std::cout << "Deconstructor is called" << std::endl;
        //No heap space allocated in this case so no need to explicitly release
    }

    //Getter function
    //...
    //Setter functions
    //...

};






#endif