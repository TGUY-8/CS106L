#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write_to_files(string name);
void read_files(string name);


int main()
{
    string name = "example.txt";
    write_to_files(name);
    read_files(name);
    return 0;
}

void write_to_files(string name){
    ofstream op_file(name);
    if(!op_file.is_open()){
        cout << "Failed to open the file" << endl;
    }
    string content;
    for (int i = 0; i < 3; i++)
    {
    getline(cin , content);
    op_file << content << '\n';
    }
    op_file << flush;
    op_file.close();
}

void read_files(string name)
{
    ifstream ip_file(name);
    if (!ip_file.is_open())
    {
        cout << "Failed to open the file" << endl;
    }
    string line;
    while (getline(ip_file , line))
    {
        cout << line << endl;
    }
    ip_file.close();
}