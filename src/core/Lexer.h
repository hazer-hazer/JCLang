#ifndef LEXER_H
#define LEXER_H

#include "Stream.h"
#include "token.h"

#include <fstream>
#include <vector>

using std::vector;
using std::string;

using std::isspace;
using std::isdigit;
using std::isalpha;
using std::ispunct;

using std::stod;
using std::stoi;

class Lexer{
    private:
        void error(string text, bool fatal = 1){
            input.error(text, fatal);
        }
    
        Stream input;
        vector <token> tokens;

        void add_token(token t);

        char peek();
        char advance();
        bool end();

        // Determination functions
        bool is_whitespace(char c);
        bool is_num(char c);
        bool is_quote(char c);
        bool is_op(char c);
        bool is_id(char c);
        bool is_id_first(char c);
        
        // Set current char as default
        bool is_whitespace(){
            return is_whitespace(peek());
        };
        bool is_num(){
            return is_num(peek());
        };
        bool is_quote(){
            return is_quote(peek());
        }
        bool is_op(){
            return is_op(peek());
        };
        bool is_id(){
            return is_id(peek());
        };
        bool is_id_first(){
            return is_id_first(peek());
        }

        // Debug-Internal
        bool const log = false; // If false - all logs will be set to false
        bool logComparisons = log;
        bool logTrueComparisons = false;
    public:
        Lexer();
        Lexer(char const * code);
        virtual ~Lexer();

        vector <token> lex();
};

#endif