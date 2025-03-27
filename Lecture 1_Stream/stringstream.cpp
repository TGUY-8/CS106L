#include <iostream>
#include <sstream>
using namespace std;

int StringToInt(const string& str);
void PrintStateBits(istringstream& iss);

int main()
{ 
    stringstream os("Initial content in buffer");    //By defalut , whatever you put in the buffer , it starts to be written in from the start at the buffer and override whatever is already existed
    cout << os.str() << endl;  //here you can chain them up because the result of first opeation is actually os itself by which i mean the return value of os << method is the stream itself
    
    os << "more stuff here" << 111; 
    cout << os.str() << endl;
   
   
    ostringstream oss("Initial content in buffer" , stringstream::ate);   //By stringstream::ate (at end) , the next you wirte in the buffer , it starts from the end
    cout << oss.str() << endl;
    
    oss << " more stuff here";                      
    cout << oss.str() << endl;

    StringToInt(oss.str());

    //

    istringstream iss("16.9 Ounces");

    int amount;
    string unit;

    iss >> amount;   //the stringstream automatically excute the type convertion to whatever type you assigned to
    iss >> unit;

    cout << amount;
    return 0;

}

//the stream is essentially a buffer that complete the transition between out source and program environment
//One thing noticable is that the flow direction of output stream and input stream is where the program data goes
//and program data is specifficaly the data that is directly managed by the program including varibles , arrays , the space which you malloc .etc
//program -> outside , output   outside -> program, inpput
//Stringstream <sstream> is a specific type of stream that only includes a two-ends transmisson between the program and the buffer
//by type-name ostringstream and istringstream you can respectively create a instance of the stringstream class

int StringToInt(const string& str)
{
    istringstream iss(str);
    PrintStateBits(iss);
    int result;
    iss >> result;
    PrintStateBits(iss);
    return result;
}

void PrintStateBits(istringstream& iss)
{
    cout << "Current state:" << endl;
    
    cout << (iss.good() ? 'G' : '*')<< endl;
    cout << (iss.fail() ? 'F' : '*' )<< endl;
    cout << (iss.eof() ? 'E' : '*') << endl;
    cout << (iss.bad() ? 'B' : '*') << endl;
}