#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;

void BadWelcomeProgram();
void cin_exp();
int StringTointeger(string prompt);


int main()
{
    void cin_exp();
    //BadWelcomeProgram();
    string str = "Please enter an integer:";
    StringTointeger(str);
    return 0;
}

void WelcomeProgram()
{
    string name;
    int age;
    
    cout << "What's ur name? ";
    //cin >> name;
    getline(cin , name);

    cout << "What's ur age ";
    cin >> age;
    cout << "Hello " << name << " (age " << age << ')' << endl;
}

int StringTointeger(string prompt)
{
   //getline -> string -> ini_iss -> int
   string tokens;
   int result ; char trash;
   while (true)
   {
    cout << prompt << endl;
    
    if (!getline(cin , tokens))
    {
        throw domain_error("invalid input!");
    }
    
    istringstream iss(tokens);

    if (iss >> result && ! (iss >> trash))
    {
        return result;
    }
   }
}

void traverse_string()
{
    string str = "Hello , World!";
    for (size_t i = 0; i < str.size(); i++)
    {
        cout << str[i] << endl;
    }
}

//auto
auto calculateSum(const vector<string>& v){
    auto multiplier = 2.4; //double
    auto name = "Avery";  //char* (C-string)
    auto betterName1 = string{"Avery"}; //string
    const auto& betterName2 = string{"Avery"}; //const string&
    auto copy = v; //vector<string>
    auto& refMult = multiplier;   //double&
    auto func = [](auto i) {return i*2};  //a lambda function

    return betterName1;
}