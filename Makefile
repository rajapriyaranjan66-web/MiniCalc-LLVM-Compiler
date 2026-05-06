all:
	bison -d parser/parser.y
	flex lexer/lexer.l
	clang lex.yy.c parser.tab.c src/main.c src/ast.c src/semantic.c src/ir.c -o compiler

run:
	./compiler tests/sample.dsl

clean:
	rm -f compiler lex.yy.c parser.tab.c parser.tab.h