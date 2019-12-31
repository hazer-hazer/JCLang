#include "Lexer.h"
#include <stdlib.h>

#include <iostream>

using namespace std;

Lexer::Lexer(){};
Lexer::~Lexer(){};

// Add multiple 
Lexer::Lexer(char const * code){
    Input input(code);
    this->input = input;

    logComparisons = log;
}

void Lexer::add_token(token t){
    tokens.push_back(t);
}

char Lexer::peek(){
    return input.peek();
}
char Lexer::advance(){
    return input.advance();
}
bool Lexer::end(){
    return input.end();
}

// Determination functions
bool Lexer::is_whitespace(char c){
    if(logComparisons)
        cout << "Lexer:[is_whitespace] " << isspace(c) << " for current: `" << peek() << "`" << endl;

    return isspace(c);
}
bool Lexer::is_quote(char c){
    if(logComparisons)
        cout << "Lexer:[is_quote] " << (c == '"' || c == '\'') << " for current: `" << peek() << "`" << endl;

    return c == '"' || c == '\'';
}
bool Lexer::is_op(char c){
    if(logComparisons)
        cout << "Lexer:[is_op] " << ispunct(c) << " for current: `" << peek() << "`" << endl;

    return ispunct(c);
    // return is_op_type(c);
}
bool Lexer::is_num(char c){
    if(logComparisons)
        cout << "Lexer:[is_num] " << isdigit(c) << " for current: `" << peek() << "`" << endl;

    return isdigit(c);
}
bool Lexer::is_id(char c){
    if(logComparisons)
        cout << "Lexer:[is_id] " << isalpha(c) << " for current: `" << peek() << "`" << endl;

    return isalpha(c) & !is_whitespace(c) & !is_quote(c) & !is_op(c) & !is_num(c);
}

vector <token> Lexer::lex(){
    token t;
    while(!end()){
        if(is_whitespace()){
            advance();
            continue;
        }else if(is_num()){
            string num(1, peek());

            while(is_num(advance()))
                num += peek();

            bool isDouble = false;
            if(peek() == '.'){
                isDouble = true;
                do num += peek();
                while(is_num(advance()));
            }

            if(isDouble)
                t.set(atof(num.c_str()));
            else
                t.set(atoi(num.c_str()));
        }else if(is_op()){
            // Add multiple !!!
            string op(1, peek());
            cout << "Lexer:[Starting parsing op] " << op << endl;
            t.set(op);
            t.set_type(OP);
            advance();
        }else if(is_quote()){
            string str = "";
            char quote = peek();
            while(advance() != quote){
                if(end()){
                    error("Closing quote "+ to_string(quote) +" expected");
                    break;
                }else
                    str += peek();
            }
            t.set(str, 0);
        }else if(is_id()){
            string id;
            do id += peek();
            while(is_id(advance()));
            t.set(id);
        }else{
            error("Unrecognized token");
        }
        // Add new token!
        add_token(t);
    }

    return tokens;
}