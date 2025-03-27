#include <iostream>
#include <windows.h>
//#include <cstdio>
using namespace std;

void experiment(ostream& oss);
void endl_eachtime();
void endl_onceatend();

int main()
{
    //setvbuf(stdout , nullptr , _IOLBF , 1024);
    //endl_eachtime();
    //endl_onceatend(); //faster one
    experiment(cout);
    return 0;
}


void experiment(ostream& oss)
{
    oss << "CS";
    Sleep(2000);
    oss << "106";
    Sleep(2000);
    oss << "L" << endl;
}

void endl_eachtime()
{
    for (int i = 0; i < 100; i++)
    {
        cout << i << endl;
    }
}

void endl_onceatend()
{
    for (int i = 0; i < 100; i++)
    {
        cout << i <<'\n';
    }
    cout << flush;
}