#include <optional>
#include <string>
#include <fstream>
#include <iostream>

//optional is a template class which will either contain a value of typeT or contain nothing(expressed as nullopt, similar)

//Common patterns
//1. function may be return a nonvalid result(input is unvalid for example)
// std::optional<std::string> readConfig(const std::string& key){
//     if(!key.empty()) return XX;
//     else return {};
// }
//2.deley the initialization
// class ResourceHolder{
//     private:
//     std::optional<Resource> resource; // initialize to empty and load when needed
//     public:
//     void load(){
//         resource.emplace(.....);
//     }
// }
//3.as a optional parameter
// void processDate(const Data& data, std::optional<int> timeout = std::nullopt){
//     if(timeout){
//         xxx
//     }
//     else{
//         xxx
//     }
// }
std::optional<int> stin(const std::string& s){
    int ret;
    try{
    ret = std::stoi(s);
    return ret;
    }
    catch(...){
        return {};
    }
}

int main(){
    std::string a = "unable with int conversion";
    int ret = stin(a).value_or(0);
    std::cout << ret << std::endl;
    return 0;
}