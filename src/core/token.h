#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <cstring>

#include <iostream>

using namespace std;

using std::string;
using std::to_string;


typedef enum{
    NONE, // ?????
    // Operators
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    POW,
    // Binary operators
    AND,
    OR,
    XOR,
    // =
    ASSIGN
} op_type;

struct{
    char const * name;
    op_type type;
} op_types[] = {
    { "+", PLUS },
    { "-", MINUS },
    { "*", MULT },
    { "/", DIV },
    { "%", MOD },
    { "=", ASSIGN }
};

#define OP_TYPES_SIZE (sizeof(op_types)/sizeof(op_types[0]))

inline op_type find_op_type(char * name){
    for(auto opt : op_types)
        if(opt.name == name)
            return opt.type;
    return NONE;
}

inline bool is_op_type(char * name){
    if(find_op_type(name) != NONE)
        return true;
    return false;
}

// Add smart types support (uint and etc.)
typedef union{
    int Int;
    double Double;
    // No char - 1 length strings ! ((((((
    // String stores value for "string" value and also for identifier
    char * String;
    bool Bool;
    op_type Op;
} token_types;

// Type of token
typedef enum{
    OP,
    ID,
    STR,
    DOUBLE,
    INT,
    BOOL
} token_type_name;

typedef struct{
    token_types val;
    token_type_name type;
    void set(int Int){
        val.Int = Int;
        type = INT;
    }
    void set(double Double){
        val.Double = Double;
        type = DOUBLE;
    }
    void set(char * String, bool is_iden = 1){
        val.String = String;
        type = STR;
    }
    void set(string str, bool is_iden = 1){
        char cstr[str.size() + 1];
        strcpy(cstr, str.c_str());
        set(cstr, is_iden);
    }
    void set(op_type Op){
        val.Op = Op;
        type = OP;
    }
    void setOp(char * name){
        set(find_op_type(name));
    }
    token_types get(){
        return val;
    }
    token_type_name getType(){
        return type;
    }

    // set_type is using for cases where operator or anything else can be different type,
    // like "else" is string but operator
    void set_type(token_type_name type_name){
        type = type_name;
    }
    
    bool is_typeof(token_type_name type_name){
        return type == type_name;
    }

    // For Debug
    string getStringVal(){
        if(type == DOUBLE)
            return to_string(val.Double);
        if(type == INT)
            return to_string(val.Int);
        if(type == STR || type == ID)
            return val.String;
        if(type == BOOL)
            return to_string(val.Bool);
        if(type == OP)
            return to_string(val.Op);
        
        return "Cannot recognize type of token";
    }
} token;

#endif