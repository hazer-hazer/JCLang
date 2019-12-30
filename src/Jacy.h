#ifndef JACY_H
#define JACY_H

#include "Parser.h"
#include "Lexer.h"

class Jacy{
    private:
        Lexer lexer;
        Parser parser;
};

#endif