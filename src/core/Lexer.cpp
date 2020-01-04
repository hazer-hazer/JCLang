#include "Lexer.h"
#include <stdlib.h>

#include <iostream>

using namespace std;

Lexer::Lexer(){};
Lexer::~Lexer(){};

// Add multiple 
Lexer::Lexer(char const * code){
    Stream input(code);
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

    return c == '!' || c == '#' || c == '%' || c == '&' || (c >= '(' && c <= '/') || (c >= ':' && c <= '@')
        || c == '`' || (c >= '[' && c <= '^') || (c >= '{' && c <= '~');
}
bool Lexer::is_num(char c){
    if(logComparisons)
        cout << "Lexer:[is_num] " << isdigit(c) << " for current: `" << peek() << "`" << endl;

    return isdigit(c);
}
bool Lexer::is_id_first(char c){
    if(logComparisons)
        cout << "Lexer:[is_id_first] " << isalpha(c) << " for current: `" << peek() << "`" << endl;

    return isalpha(c) || c == '_' || c == '$';
}
bool Lexer::is_id(char c){
    if(logComparisons)
        cout << "Lexer:[is_id] " << isalpha(c) << " for current: `" << peek() << "`" << endl;
    return isalnum(c) || is_id_first(c);
}

// 
vector <token> Lexer::lex(){
    token t;
    while(!end()){
        if(is_whitespace()){
            advance();
            continue;
        }else if(is_num()){
            if(logTrueComparisons)
                cout << "[Lexer] " << peek() << " is num" << endl;

            string num;
            num += peek();

            while(is_num(advance()))
                num += peek();

            bool isDouble = false;
            if(peek() == '.'){
                isDouble = true;
                do num += peek();
                while(is_num(advance()));
            }

            if(isDouble)
                t.setVal((double)stod(num.c_str()));
            else
                t.setVal((int)stoi(num.c_str()));
        }else if(is_op()){
            if(logTrueComparisons)
                cout << "[Lexer] " << peek() << " is op" << endl;

            // Add multiple !!!
            string op(1, peek());
            t.setOpVal(op.c_str());
            advance();
        }else if(is_quote()){
            if(logTrueComparisons)
                cout << "[Lexer] " << peek() << " is quote" << endl;

            char quote = peek();
            string str;
            while(advance() != quote){
                if(end()){
                    // Add `Expected` error
                    error("Closing quote `"+ string(1, quote) +"` expected");
                    break;
                }
                str += peek();
            }
            advance();
            t.setVal(str, 0);
        }else if(is_id_first()){
            if(logTrueComparisons)
                cout << "[Lexer] " << peek() << " is id" << endl;

            string id(1, peek());
            while (is_id(advance()))
                id += peek();
            
            // Set can be different, because operators and keywords can also be a identifier-like
            if(is_kw_type(id.c_str()))
                t.setKwVal(id.c_str());
            else if(is_op_type(id.c_str()))
                t.setOpVal(id.c_str());
            else
                t.setVal(id);
        }else{
            string mes = "Unrecognized token: `" + to_string(peek()) + "`";
            error(mes.c_str());
        }
        // Add new token!
        add_token(t);
    }

    t.type = SYSTEM;
    t.setVal(END);
    add_token(t);

    return tokens;
}