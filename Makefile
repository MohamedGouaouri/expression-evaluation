calc: calc.l calc.y ast.h
	bison -d calc.y
	flex calc.l
	cc -o $@ calc.tab.c calc.lex.c ast.c -lfl -lm


clean: calc.tab.c calc.lex.c calc
	rm calc.tab.c calc.lex.c calc