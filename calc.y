%{
    #include "ast.h"

    extern int yylex();
    void yyerror(char *s);
%}



// to give tokens a type
%union{
    struct ast* a;
    int d;
}

// declare tokens
%token <d> number
%token EOL // end of line

%type <a> exp


// precedence and assoc
%left '+' '-' //lowest
%left '*' 
%left '^'
%left '(' ')' // highest

// Grammar
%%
calc:
    | calc exp  {
            printf("evaluation = %d\n", eval($2));
            freeast($2);
            // printf("> ");
        }
    | calc EOL {printf("> ");}
    ;


exp: exp '+' exp {
        $$ = newast('+', $1, $3);
    }
    | exp '-' exp {$$ = newast('-', $1, $3);}
    | exp '*' exp {$$ = newast('*', $1, $3);}
    | exp '^' exp {$$ = newast('^', $1, $3);}
    | '(' exp ')' {$$ = $2;}
    | number {
        $$ = newnum($1);
    }
    ;
%%


void yyerror (char *s) {
   fprintf (stderr, "%s\n", s);
 }


int main(){

    fflush(stdout);
    printf("> ");
    yyparse();
}