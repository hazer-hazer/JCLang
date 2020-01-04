#include "Parser.h"

Parser::Parser(){}
Parser::~Parser(){}

symbol Parser::peek(){
    // @Optimize
    symbol current;
    current.init(tokens[index]);
    return current;
}

symbol Parser::advance(){
    index++;
    return peek();
}

bool Parser::isSystem(symbol s, system_type st){
    return s.type == SYSTEM && s.equals(st);
}
bool Parser::isNum(symbol s){
    return s.type == DOUBLE || s.type == INT;
}
bool Parser::isString(symbol s){
    return s.type == STR;
}
bool Parser::isId(symbol s){
    return s.type == ID;
}
bool Parser::isOp(symbol s, op_type ot){
    return s.type == OP && s.equals(ot);
}
bool Parser::isBool(symbol s){
    return s.type == BOOL;
}

bool Parser::isSystem(system_type st){
    return isSystem(peek(), st);
}
bool Parser::isNum(){
    return isNum(peek());
} 
bool Parser::isString(){
    return isString(peek());
}
bool Parser::isId(){
    return isId(peek());
}
bool Parser::isBool(){
    return isBool(peek());
}
bool Parser::isOp(op_type ot){
    return isOp(peek(), ot);
}

// void Parser::skip(symbol s){
//     if(peel() == s)
//         advance();
//     else
//         cout << s.getType() << " " << s.getStringVal() << " expected" << endl;
//     // else error(s  expected) !!!
// }

// node * Parser::parse_block(){
//     skip({ type = OP, val = BRACE_L });
    
//         node * prog = expr();
//     skip({ type = OP, val = BRACE_R });

// }

// node * Parser::expr(){
//     if(isNum()){
//         val_node * n;
//         n->set(peek());
//         advance();
//         return n;
//     }else if(isOp()){
//         // END HERE
//         parse_op(left);
//     }
// }

// Tree Parser::parse(vector <token> tokens){
//     index = 0;
//     this->tokens = tokens;

//     Tree tree;
//     while(!isSystem(END)){
//         cout << "[Parser] current symbol is type of: " << peek().type << " " << peek().getStringVal() << endl;
//         tree.push_back(expr(0));
//     }

//     return tree;
// }