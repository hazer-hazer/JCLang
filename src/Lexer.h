#ifndef LEXER_H
#define LEXER_H

#include "Input.h"

#include <iostream>

class Lexer{
    private:
        Input input;

    public:
        // Setters / Getters
        void setInput(Input input);

        Lexer();
        Lexer(Input *input);
        ~Lexer();
};

#endif