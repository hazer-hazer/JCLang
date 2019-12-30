#include "Input.h"

Input::Input(char * inputText){
    this->inputText = inputText;
    current = ' ';
    index = 0;
}

Input::~Input(){}

char Input::peek(){
    current = inputText[index];
    if(current == '\n'){
        line++;
        cursor = 0;
    }else cursor++;

    return current;
}

char Input::advance(){
    index++;
    return peek();
}