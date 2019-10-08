//*****************************************************************************
// CSE 4713 / 6713 Assignment 2 Driver File
//*****************************************************************************
#include <stdio.h>


extern "C"
{
// Instantiate global variables
#include "lexer.h"
extern FILE *yyin;         // input stream
extern FILE *yyout;        // output stream
extern int   yyleng;       // length of current lexeme
extern char *yytext;       // text of current lexeme
extern int   yylex();      // the generated lexical analyzer
}

// Do the analysis
int main( int argc, char* argv[] )
{
  int token;   // hold each token code

  // Set the input and output streams
  yyin = fopen("sample.in", "r");
  yyout = stdout;

  // Do the lexical parsing
  token = yylex();
  while( token != TOK_EOF ) 
  {
    // What did we find?
    printf("lexeme: |%s|, length: %d, token: %d\n", yytext, yyleng, token);
    // Is it an error?
    if( token == TOK_UNKNOWN )
      printf("   ERROR: unknown token\n");
    if( token == TOK_EOF_SL )
      printf("   ERROR: unterminated string\n");
    // Get the next token
    token = yylex();
  }
}
