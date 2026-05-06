#include <stdio.h>

void generateIR() {

    FILE *fp = fopen("output/output.ll", "w");

    fprintf(fp,
"define i32 @main() {\n"
"entry:\n"
"  %%a = alloca i32\n"
"  store i32 10, i32* %%a\n"
"  ret i32 0\n"
"}\n"
);

    fclose(fp);

    printf("LLVM IR Generated\n");
}