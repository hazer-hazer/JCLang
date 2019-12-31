#include "Input.h"
#include <iostream>

using namespace std;

Input::Input(){}
Input::~Input(){}

Input::Input(char const * inputText){
    this->inputText = inputText;
    current = ' ';
    index = 0;
    lastIndex = 0; // For line-cursor control

    line = 0;
    cursor = 0;

    size = strlen(inputText);
}

char Input::peek(){
    current = inputText[index];
    
    return current;
}

char Input::advance(){
    if(current == '\n'){
        line++;
        cursor = 0;
    }else cursor++;
    
    index++;
    return peek();
}

bool Input::end(){
    return index >= size;
}