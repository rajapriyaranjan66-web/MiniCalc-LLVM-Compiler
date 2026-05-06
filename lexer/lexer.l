%{
#include "parser.tab.h"
#include <stdlib.h>
%}

%%

"let"          { return LET; }
"print"        { return PRINT; }

[0-9]+         {
                    yylval.num = atoi(yytext);
                    return NUMBER;
               }

[a-zA-Z_][a-zA-Z0-9_]* {
                    yylval.str = strdup(yytext);
                    return IDENTIFIER;
               }

"+"            { return PLUS; }
"-"            { return MINUS; }
"*"            { return MUL; }
"/"            { return DIV; }

"="            { return ASSIGN; }

"("            { return LPAREN; }
")"            { return RPAREN; }

";"            { return SEMICOLON; }

[ \t\n]        ;

.              {
                    printf("Unknown character: %s\n", yytext);
               }

%%

int yywrap() {
    return 1;
}