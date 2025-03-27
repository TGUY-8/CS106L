#include <string>
class StudentID{
    private:
    std::string name;
    std::string sunet;
    int idNumber;
    public:
    //Constructor
    StudentID(std::string name, std::string sunet, int idNumber) {}
    //Default-Constructor
    StudentID() {}
    //Destructor
    ~StudentID();

    //Getter functions
    std::string getname();
    std::string getsunet();
    int getID();

    //Setter functions
    void setName(std::string name);
    void setSunet(std::string sunet);
    void setID(int idnumber);
};