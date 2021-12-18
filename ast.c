#include "ast.h"
#include "stdlib.h"
#include "math.h"

ast *newast(int nodeType, ast *left, ast *right)
{
    ast *a = (ast *)malloc(sizeof(ast));
    if (a == NULL)
    {
        printf("Out of space\n");
        exit(EXIT_FAILURE);
    }
    a->nodeType = nodeType;
    a->left = left;
    a->right = right;
}

ast *newnum(int d)
{
    numval *a = (numval *)malloc(sizeof(numval));
    if (a == NULL)
    {
        printf("out of space\n");
        exit(EXIT_FAILURE);
    }

    a->nodeType = 'K';
    a->number = d;
    return (struct ast *)a;
}

int eval(ast *a)
{
    int evaluation;

    // recurssively evaluate the tree
    switch (a->nodeType)
    {
    case 'K':
        /* a constant number */
        // cast the node to a numval
        evaluation = ((numval *)a)->number;

        break;
    case '+':
        evaluation = eval(a->left) + eval(a->right);
        break;
    case '-':
        evaluation = eval(a->left) - eval(a->right);
        break;
    case '*':
        evaluation = eval(a->left) * eval(a->right);
        break;
    case '^':
        evaluation = (int)pow(eval(a->left), eval(a->right));
        break;
    default:
        printf("internal error: bad node %c\n", a->nodeType);
        break;
    }
}

void freeast(ast *a)
{
    // recurssively evaluate the tree
    switch (a->nodeType)
    {
    case 'K':
        free(a);
        break;
    case '+':
    case '-':
    case '*':
    case '^':
        freeast(a->right);
        freeast(a->left);
        break;
    default:
        printf("internal error: bad node %c\n", a->nodeType);
        break;
    }
}