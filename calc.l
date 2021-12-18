%option noyywrap nodefault yylineno
%option outfile = "calc.lex.c"
%{
    #include "calc.tab.h"
%}
NUMBER [1-9][0-9]*

%%

{NUMBER} {
    yylval.d = atof(yytext);
    return number;
}

[-+*=/\(\)\^;]   {
    return yytext[0];
}


\n {return EOL;}



"//".* 

[ \t] { /* ignore whitespace */ }

. { 
    printf("unexpected character %c\n", *yytext); 
    yyterminate();
}

%%