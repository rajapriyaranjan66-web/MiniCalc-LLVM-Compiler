#include <stdio.h>

extern FILE *yyin;
extern int yyparse();

void semanticCheck();
void generateIR();

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Usage: ./compiler <file>\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");

    if(!yyin) {
        printf("Cannot open file\n");
        return 1;
    }

    yyparse();

    semanticCheck();

    generateIR();

    printf("Compilation Successful\n");

    return 0;
}