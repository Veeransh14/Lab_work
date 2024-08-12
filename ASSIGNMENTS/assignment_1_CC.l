%{
#include <stdio.h>
%}

%%
"int"|"float"|"char" { printf("DATATYPE: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("VARIABLE NAME: %s\n", yytext); }
"=" { printf("EQUAL TO OPERATOR: %s\n", yytext); }
"," { printf("COMMA: %s\n", yytext); }
[0-9]+ { printf("NUMBER: %s\n", yytext); }
";" { printf("SEMICOLON: %s\n", yytext); }
[ \t\n] { /* Ignore whitespace */ }
. { printf("UNKNOWN: %s\n", yytext); }

%%

int main(void) {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
