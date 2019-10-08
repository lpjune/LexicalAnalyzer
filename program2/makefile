###############################################################################
# CSE 4713 / 6713 Assignment 2 example flex file
###############################################################################
LEX		=	flex
.PRECIOUS 	=	driver.cpp rules.l lexer.h	

lex.exe: lex.yy.o driver.o
	g++ -o $@ $^

lex.yy.o: lex.yy.c lexer.h
	cc -o $@ -c lex.yy.c

driver.o: driver.cpp lexer.h
	g++ -o $@ -c driver.cpp

lex.yy.c: rules.l
	$(LEX) $^

clean: 
	$(RM) *.o lex.yy.c lex.exe

