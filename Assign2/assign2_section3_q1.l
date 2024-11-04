%{
#include <stdio.h>

int yywrap(void) {
    return 1;
}
// yywrap return 1 indicates no more files to process, 
// return 0 indicates no more input files to read.
// yywrap is called when lex reaches the end of the input file.
%}

%%

"main"                { printf("MAIN\n"); }
"INT"|"int"           { printf("INT\n"); }
"FLOAT"|"float"       { printf("FLOAT\n"); }
"CHAR"|"char"         { printf("CHAR\n"); }
"BOOL"|"bool"         { printf("BOOL\n"); }
"if"                  { printf("IF\n"); }
"for"                 { printf("FOR\n"); }
"while"               { printf("WHILE\n"); }
"read"                { printf("READ\n"); }
"out"                 { printf("OUT\n"); }
"("                   { printf("LPAREN\n"); }
")"                   { printf("RPAREN\n"); }
"{"                   { printf("LBRACE\n"); }
"}"                   { printf("RBRACE\n"); }
";"                   { printf("SEMICOLON\n"); }
","                   { printf("COMMA\n"); }
"="                   { printf("ASSIGN\n"); }
"=="                  { printf("EQ\n"); }
"!="                  { printf("NEQ\n"); }
"<="                  { printf("LEQ\n"); }
">="                  { printf("GEQ\n"); }
"<"                   { printf("LT\n"); }
">"                   { printf("GT\n"); }
"+"                   { printf("PLUS\n"); }
"-"                   { printf("MINUS\n"); }
"*"                   { printf("MULT\n"); }
"/"                   { printf("DIV\n"); }
[0-9]+                { printf("INT_LITERAL\n"); }
[0-9]*\.[0-9]+        { printf("FLOAT_LITERAL\n"); }
\'([^\\']|\\.)\'     { printf("CHAR_LITERAL\n"); }
\"([^\\"]|\\.)*\"     { printf("STRING_LITERAL\n"); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("IDENTIFIER\n"); }
[ \t\n]+              { /* Ignore whitespace */ }
.                     { printf("UNKNOWN '%s'\n", yytext); }

%%

int main() {
    int token;
    FILE *fp;

    char filename[50] = "input.txt";
    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error reading the file");
        return 1;
    }

    yyin = fp;

    while ((token = yylex()) != 0) {
        // Process each token
    }

    fclose(fp);
    return 0;
}