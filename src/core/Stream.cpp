#include "Stream.h"
#include <iostream>

using namespace std;

Stream::Stream(){}
Stream::~Stream(){}

Stream::Stream(char const * inputText){
    this->inputText = inputText;
    current = ' ';
    index = 0;
    lastIndex = 0; // For line-cursor control

    line = 0;
    cursor = 0;

    size = strlen(inputText);
}

char Stream::peek(){
    current = inputText[index];
    
    return current;
}

char Stream::advance(){
    if(current == '\n'){
        line++;
        cursor = 0;
    }else cursor++;

    index++;
    return peek();
}

bool Stream::end(){
    return index >= size;
}