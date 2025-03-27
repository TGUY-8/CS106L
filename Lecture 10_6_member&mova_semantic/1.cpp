#include <algorithm>

void copy(char* dst, char* src, size_t size){
    dst = new char[size];
    memcpy(dst, src, size);
}

void move(char* dst, char* src){
    dst = src;
    src = nullptr;
}