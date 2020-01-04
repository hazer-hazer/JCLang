#ifndef PARSER_H
#define PARSER_H

#include "symbol.h"
#include "node.h"
#include "val_node.h"
#include <vector>

#include <iostream>

using std::cout;

typedef vector <symbol*> Tree;

class Parser{
    private:
        vector <token> tokens;
        int index;

        symbol peek();
        symbol advance();

        void skip(symbol s);

        node * expr(int prec);
        node * parse_op();
        node * parse_block();
    

        // Comparison
        bool isSystem(symbol s, system_type st);
        bool isNum(symbol s); // For parsing no difference between double and int
        bool isString(symbol s);
        bool isId(symbol s);
        bool isOp(symbol s, op_type ot);
        bool isBool(symbol s);

        bool isSystem(system_type st);
        bool isNum();
        bool isString();
        bool isId();
        bool isOp(op_type ot);
        bool isBool();

    public:
        Parser();
        virtual ~Parser();

        Tree parse(vector <token> tokens);
};

#endif