//*****************************************************************************
// purpose: CSE 4713 / 6713 Assignment 1: Lexical Analyzer
// created: 9-17-2019
// author: Lauren Orsini
//*****************************************************************************
#include "lexer.h"
#include <ctype.h>
#include <assert.h>
#include <string.h>

//*****************************************************************************
// Do the lexical parsing
char lexeme[MAX_LEXEME_LEN];  // Character buffer for lexeme
int yylex()
{
	static char c = -1;         // Have we read the first character yet?
	int char_type;              // Hold the character type

	// Prepare the buffer to hold the lexeme
	for (int i = 0; i < MAX_LEXEME_LEN; i++)
		lexeme[i] = '\0';
	yytext = lexeme;
	yyleng = 0;

	// If the very first character has not yet been read, read it
	if (c < 0)
		c = fgetc(yyin);

	// Test for end of file
	if (feof(yyin)) {
		// Ready for next time
		c = -1;
		// Done!
		return(TOK_EOF);
	}
	

	// whitespace
	// take input while whitespace/underscore alone/new line
	while (c == ' ' || c == '_' || c == '\n') {
		c = fgetc(yyin);
	}

	// stringlit
	// if quotation
	if (c == '"') {
		lexeme[yyleng++] = c;
		c = fgetc(yyin);
		yytext = lexeme;
		// take input until closing quotation
		while (c != '"') {
			lexeme[yyleng++] = c;
			c = fgetc(yyin);
			yytext = lexeme;
		}
		lexeme[yyleng++] = c;
		c = fgetc(yyin);
		yytext = lexeme;
		return(TOK_STRINGLIT);
	}

	// keyword & identifier
	// start with letter
	if (isalpha(c)) {
		lexeme[yyleng++] = c;
		c = fgetc(yyin);
		yytext = lexeme;
		// take input while letter/number/underscore
		while (isalnum(c) || c == '_') {
			lexeme[yyleng++] = c;
			c = fgetc(yyin);
			yytext = lexeme;
		}
		// check if lexeme is a keyword
		if (strcmp(yytext, "if") == 0) {
			return(TOK_IF);
		}
		else if (strcmp(yytext, "else") == 0) {
			return(TOK_ELSE);
		}
		else if (strcmp(yytext, "for") == 0) {
			return(TOK_FOR);
		}
		else if (strcmp(yytext, "while") == 0) {
			return(TOK_WHILE);
		}
		else if (strcmp(yytext, "print") == 0) {
			return(TOK_PRINT);
		}
		else if (strcmp(yytext, "return") == 0) {
			return(TOK_RETURN);
		}
		else if (strcmp(yytext, "continue") == 0) {
			return(TOK_CONTINUE);
		}
		else if (strcmp(yytext, "break") == 0) {
			return(TOK_BREAK);
		}
		else if (strcmp(yytext, "debug") == 0) {
			return(TOK_DEBUG);
		}
		else if (strcmp(yytext, "read") == 0) {
			return(TOK_READ);
		}
		else if (strcmp(yytext, "let") == 0) {
			return(TOK_LET);
		}
		else if (strcmp(yytext, "int") == 0) {
			return(TOK_INT);
		}
		else if (strcmp(yytext, "float") == 0) {
			return(TOK_FLOAT);
		}
		else if (strcmp(yytext, "string") == 0) {
			return(TOK_STRING);
		}
		else if (strcmp(yytext, "and") == 0) {
			return(TOK_AND);
		}
		else if (strcmp(yytext, "or") == 0) {
			return(TOK_OR);
		}
		else if (strcmp(yytext, "not") == 0) {
			return(TOK_NOT);
		}
		else if (strcmp(yytext, "len") == 0) {
			return(TOK_LENGTH);
		}
		// if not keyword, identifier
		else {
			return(TOK_IDENTIFIER);
		}
	}

	// float & int
	// start with digit
	if (isdigit(c)) {
		lexeme[yyleng++] = c;
		c = fgetc(yyin);
		yytext = lexeme;
		// take input while digit
		while (isdigit(c)) {
			lexeme[yyleng++] = c;
			c = fgetc(yyin);
			yytext = lexeme;
			// if decimal, keep going while digit after decimal
			if (c == '.') {
				lexeme[yyleng++] = c;
				c = fgetc(yyin);
				yytext = lexeme;
				while (isdigit(c)) {
					lexeme[yyleng++] = c;
					c = fgetc(yyin);
					yytext = lexeme;
				}
				return(TOK_FLOATLIT);
			}
		}
		return(TOK_INTLIT);
		
	}

	// punctuation
	if (c == ';') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_SEMICOLON);
	}

	else if (c == '(') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_OPENPAREN);
	}

	else if (c == ')') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_CLOSEPAREN);
	}

	else if (c == '[') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		return(TOK_OPENBRACKET);
	}

	else if (c == ']') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_CLOSEBRACKET);
	}

	else if (c == '{') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_OPENBRACE);
	}

	else if (c == '}') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_CLOSEBRACE);
	}

	else if (c == ',') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_COMMA);
	}

	else if (c == '+') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_PLUS);
	}

	else if (c == '-') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_MINUS);
	}

	else if (c == '*') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_MULTIPLY);
	}

	else if (c == '/') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_DIVIDE);
	}

	else if (c == ':') {
		lexeme[yyleng++] = c;
		c = fgetc(yyin);
		yytext = lexeme;
		if (c == '=') {
			c = fgetc(yyin);
			return(TOK_ASSIGN);
		}
		else {
			c = fgetc(yyin);
			return(TOK_UNKNOWN);
		}
	}

	else if (c == '=') {
		lexeme[yyleng++] = c;
		c = fgetc(yyin);
		yytext = lexeme;
		if (c == '=') {
			c = fgetc(yyin);
			return(TOK_EQUALTO);
		}
		else {
			c = fgetc(yyin);
			return(TOK_UNKNOWN);
		}
	}

	else if (c == '<') {
		lexeme[yyleng++] = c;
		c = fgetc(yyin);
		if (c == '>') {
			lexeme[yyleng++] = c;
			c = fgetc(yyin);
			yytext = lexeme;
			return(TOK_NOTEQUALTO);
		}
		else {
			lexeme[yyleng++] = c;
			c = fgetc(yyin);
			yytext = lexeme;
			return(TOK_LESSTHAN);
		}
	}

	else if (c == '>') {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_GREATERTHAN);
	}

	// if nothing else, return unknown lexeme
	else {
		lexeme[yyleng++] = c;
		yytext = lexeme;
		c = fgetc(yyin);
		return(TOK_UNKNOWN);
	}

}
