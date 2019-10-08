/*****************************************************************************
// CSE 4713 / 6713 Assignment 2 Flex File
*****************************************************************************/
%option noyywrap
%{
#include "lexer.h"
%}

%%
 
if  { return TOK_IF; }
else { return TOK_ELSE; }
for { return TOK_FOR; }
while { return TOK_WHILE; }
print { return TOK_PRINT; }
return { return TOK_RETURN; }
continue { return TOK_CONTINUE; }
break { return TOK_BREAK; }
debug { return TOK_DEBUG; }
read { return TOK_READ; }
let { return TOK_LET; }

int { return TOK_INT; }
float { return TOK_FLOAT; }
string { return TOK_STRING; }

; { return TOK_SEMICOLON; }
\( { return TOK_OPENPAREN; }
\) { return TOK_CLOSEPAREN; }
\[ { return TOK_OPENBRACKET; }
\] { return TOK_CLOSEBRACKET; }
\{ { return TOK_OPENBRACE; }
\} { return TOK_CLOSEBRACE; }
, { return TOK_COMMA; }

\+ { return TOK_PLUS; }
- { return TOK_MINUS; }
\* { return TOK_MULTIPLY; }
\/ { return TOK_DIVIDE; }
\:= { return TOK_ASSIGN; }
\== { return TOK_EQUALTO; }
\< { return TOK_LESSTHAN; }
\> { return TOK_GREATERTHAN; }
\<> {return TOK_NOTEQUALTO; }
and { return TOK_AND; }
or {return TOK_OR; }
not { return TOK_NOT; }
len { return TOK_LENGTH; }

[A-Za-z][A-Za-z0-9_]* { return TOK_IDENTIFIER; }
[0-9]+ { return TOK_INTLIT; }
 ([0-9])+"."([0-9])* { return TOK_FLOATLIT; }
"\"".+"\"" { return TOK_STRINGLIT; }

<<EOF>> { return TOK_EOF; }


