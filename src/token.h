#ifndef TOKEN_H
#define TOKEN_H

#include "token_type.h"
#include "token_val.h"

/**
 * All the "super" tokens like "or", "and", etc. are being processed in Lexer. It makes much performance, i hope.
 * So, the token type is enum, but val is a union that stores value from lexing layer to executing.
*/

struct{
    token_type type;
    token_val val;
} token;

#endif