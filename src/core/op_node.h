#ifndef OP_NODE_H
#define OP_NODE_H

#include "node.h"

typedef enum{
    PREFIX,
    INFIX,
    POSTFIX
} op_node_type;

struct op_node : node{
    op_node_type ont;
    node * left;
    node * right;
    set(node * left, node * right){
        this->left = left;
        this->right = right;
        ont = INFIX;
    }
    set(node * left){
        this->left = left;
        ont = POSTFIX;
    }
    set(node * right){
        this->right = right;
        ont = PREFIX;
    }
};

#endif