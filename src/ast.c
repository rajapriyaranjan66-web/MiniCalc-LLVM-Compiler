#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"

ASTNode* createNode(char *type) {

    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));

    strcpy(node->type, type);

    node->value = 0;

    node->left = NULL;
    node->right = NULL;

    return node;
}