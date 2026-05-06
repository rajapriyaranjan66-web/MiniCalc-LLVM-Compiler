#include <stdio.h>
#include <string.h>

#define MAX 100

char expressions[MAX][100];
int count[MAX];

int main() {

    FILE *fp;
    char line[100];

    int n = 0;

    fp = fopen("input.txt", "r");

    while(fgets(line, sizeof(line), fp)) {

        char lhs[20], rhs[80];

        sscanf(line, "%[^=]=%s", lhs, rhs);

        int found = 0;

        for(int i=0; i<n; i++) {

            if(strcmp(expressions[i], rhs) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        if(!found) {
            strcpy(expressions[n], rhs);
            count[n] = 1;
            n++;
        }
    }

    printf("Expression Analysis\n\n");

    for(int i=0; i<n; i++) {

        printf("Expression: %s\n", expressions[i]);
        printf("Frequency: %d\n", count[i]);

        if(count[i] > 1)
            printf("Is_Common_Subexpression: TRUE\n\n");
        else
            printf("Is_Common_Subexpression: FALSE\n\n");
    }

    fclose(fp);

    return 0;
}