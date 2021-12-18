#if !defined(_AST_H)
#define _AST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ast
{
    int nodeType;
    struct ast *left;
    struct ast *right;
} ast;

typedef struct numval
{
    int nodeType;
    int number;
} numval;

// Routins to build an AST
ast *newast(int nodeType, ast *left, ast *right);
ast *newnum(int d);

// Routins to evaluate the AST
int eval(ast *);

// free the AST
void freeast(ast *);

#endif // _AST_H
