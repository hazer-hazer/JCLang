#include "Reader.h"
#include <iostream>

using namespace std;

Reader::Reader(){}
Reader::~Reader(){}

Reader::Reader(char const * inputText){
    this->inputText = inputText;
    current = ' ';
    index = 0;
    lastIndex = 0; // For line-cursor control

    line = 0;
    cursor = 0;

    size = strlen(inputText);
}

char Reader::peek(){
    current = inputText[index];
    
    return current;
}

char Reader::advance(){
    if(current == '\n'){
        line++;
        cursor = 0;
    }else cursor++;

    index++;
    return peek();
}

bool Reader::end(){
    return index >= size;
}