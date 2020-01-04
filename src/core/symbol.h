#ifndef SYMBOL_H
#define SYMBOL_H

#include "token.h"

// Symbol is parser-level token like structure
// It operates with precedence and token type

struct symbol : token{
    int prec;
    void init(token t){
        val = t.val;
        type = t.type;
    }
};

#endif