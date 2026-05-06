#ifndef AST_H
#define AST_H

typedef struct ASTNode {

    char type[20];
    int value;
    char name[50];

    struct ASTNode *left;
    struct ASTNode *right;

} ASTNode;

ASTNode* createNode(char *type);

#endif