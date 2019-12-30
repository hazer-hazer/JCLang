#include <iostream>

typedef union{
    int Int;
    float Float;
    bool Bool;
    char Char;
    std::string String; 
} token_val;