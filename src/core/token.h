#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <cstring>
#include <variant>

#include <iostream>

using namespace std;

using std::string;
using std::to_string;
using std::variant;

// Operators types
// All the types of operators, but not all are implemented
typedef enum{
    OP_NONE, // ?????
    // Math
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    POW,
    // Vars-Math
    INCR,
    DECR,
    // Logical
    AND,
    OR,
    NOT,
    XOR,
    // Brackets
    BRACE_L,
    BRACE_R,
    BRACKET_L,
    BRACKET_R,
    PAREN_L,
    PAREN_R,
    // Comparison
    LESS,
    GREATER,
    EQUALS,
    GREATER_EQ,
    LESS_EQ,
    NOT_EQ,
    // Assignment
    ASSIGN,
    PLUS_ASSIGN,
    MINUS_ASSIGN,
    MULT_ASSIGN,
    DIV_ASSIGN,
    MOD_ASSIGN,
    POW_ASSIGN,
    // Puncts
    COLO,
    SEMICOLON,
    COMMA,
    DOT,
    QUESTION,
    // Bitwise
    B_NOT,
    B_AND,
    B_OR,
    B_XOR,
    LEFT_SHIFT,
    RIGHT_SHIFT,
    // Variables
    TYPEOF,
    INSTANCEOF,
    NEW
} op_type;

// All the operators that are binded to the names
struct{
    char const * name;
    op_type type;
} op_types[] = {
    { "+", PLUS },
    { "-", MINUS },
    { "*", MULT },
    { "/", DIV },
    { "%", MOD },
    // Assignment
    { "=", ASSIGN },
    // Brackets
    { "{", BRACE_L },
    { "}", BRACE_R },
    { "(", PAREN_L },
    { ")", PAREN_R }
};

// Search for operator type by string
inline op_type find_op_type(char const * name){
    for(auto opt : op_types)
        if(strcmp(opt.name, name) == 0)
            return opt.type;
    return OP_NONE;
}

// Is string an operator
inline bool is_op_type(char const * name){
    if(find_op_type(name) != OP_NONE)
        return true;
    return false;
}

// Internal
inline char const * find_op_name(op_type ot){
    for(auto op : op_types)
        if(op.type == ot)
            return op.name;
    return "Unrecognized operator name for op_type: " + ot;
}

// System types
typedef enum{
    END
} system_type;

// Keywords types
typedef enum{
    KW_NONE,
    IF,
    ELSE,
    ELIF
} kw_type;

struct{
    char const * name;
    kw_type type;
} kw_types[] = {
    { "if", IF },
    { "else", ELSE },
    { "elif", ELIF }
};

inline kw_type find_kw_type(char const * name){
    for(auto kw : kw_types)
        if(strcmp(kw.name, name))
            return kw.type;
    return KW_NONE;
}

inline bool is_kw_type(char const * name){
    return find_kw_type(name) != KW_NONE;
}

// Internal
inline char const * find_kw_name(kw_type kwt){
    for(auto kw : kw_types)
        if(kw.type == kwt)
            return kw.name;
    return "Unrecognized keyword type: " + kwt;
}
// RELIC OF THE PAST (((
// Add smart types support (uint and etc.)
// typedef union{
//     int Int;
//     double Double;
//     // No char -- 1 length strings ! ((((((
//     // String stores value for "string" value and also for identifier
//     char * String;
//     bool Bool;
//     op_type Op;
//     system_type System;
//     kw_type Keyword;
// } token_val;

typedef variant <int, double, string, bool, op_type, system_type, kw_type> token_val;

// Type of token
typedef enum{
    OP,
    ID,
    STR,
    DOUBLE,
    INT,
    BOOL,
    SYSTEM,
    KW
} token_type_name;

struct token{
    token_val val;
    token_type_name type;

    void setVal(int Int){
        val = Int;
        type = INT;
    }
    void setVal(double Double){
        val = Double;
        type = DOUBLE;
    }
    void setVal(string str, bool is_iden = 1){
        val = str;
        if(is_iden)
            type = ID;
        else
            type = STR;
    }
    void setVal(op_type opt){
        val = opt;
        type = OP;
    }
    void setVal(system_type st){
        val = st;
        type = SYSTEM;
    }
    void setVal(kw_type kwt){
        val = kwt;
        type = KW;
    }
    void setOpVal(char const * name){
        setVal(find_op_type(name));
    }
    void setKwVal(char const * name){
        setVal(find_kw_type(name));
    }

    // Equals functions
    bool equals(op_type ot){
        return std::get<op_type>(val) == ot;
    }
    bool equals(system_type st){
        return std::get<system_type>(val) == st;
    }

    // set_type is using for cases where operator or anything else can be different type,
    // like "else" is string but keyword
    void set_type(token_type_name type_name){
        type = type_name;
    }
    
    bool is_typeof(token_type_name type_name){
        return type == type_name;
    }

    // Internal
    string getStringType(){
        if(type == DOUBLE)
            return "DOUBLE";
        if(type == INT)
            return "INT";
        if(type == STR)
            return "STRING";
        if(type == ID)
            return "IDEN";
        if(type == BOOL)
            return "BOOL";
        if(type == OP)
            return "OPERATOR";
        if(type == SYSTEM)
            return "SYSTEM";
        if(type == KW)
            return "KEYWORD";

        return "Unrecognized type";
    }
    // Internal
    string getStringVal(){
        if(type == DOUBLE)
            return to_string(std::get<double>(val));
        if(type == INT)
            return to_string(std::get<int>(val));
        if(type == STR || type == ID)
            return std::get<string>(val);
        if(type == BOOL)
            return to_string(std::get<bool>(val));
        if(type == OP)
            return find_op_name(std::get<op_type>(val));
        if(type == SYSTEM)
            return to_string(std::get<system_type>(val));
        if(type == KW)
            return find_kw_name(std::get<kw_type>(val));

        return "Cannot recognize type of token";
    }
};

#endif