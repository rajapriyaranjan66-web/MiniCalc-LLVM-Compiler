%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%union {
    int num;
    char *str;
}

%token LET PRINT
%token <num> NUMBER
%token <str> IDENTIFIER

%token PLUS MINUS MUL DIV
%token ASSIGN

%token LPAREN RPAREN
%token SEMICOLON

%%

program:
    statements
;

statements:
    statements statement
    |
;

statement:
    LET IDENTIFIER ASSIGN expression SEMICOLON
        {
            printf("Variable Declared: %s\n", $2);
        }
    |
    PRINT LPAREN expression RPAREN SEMICOLON
        {
            printf("Print Statement\n");
        }
;

expression:
    expression PLUS expression
    |
    expression MINUS expression
    |
    expression MUL expression
    |
    expression DIV expression
    |
    NUMBER
    |
    IDENTIFIER
;

%%

void yyerror(const char *s) {
    printf("Parse Error: %s\n", s);
}