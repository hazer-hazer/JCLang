#ifndef NODE_H
#define NODE_H

#include "symbol.h"

struct node : symbol{
    void init(symbol s){
        prec = s.prec;
    }
};

#endif