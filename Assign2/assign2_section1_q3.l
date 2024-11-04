%{
#include <stdio.h>
#include <string.h>
%}

/* Rules Section */
%%
[a-c]{0,6}aa[a-c]{0,4}    { if (strlen(yytext) == 6) printf("Valid string with consecutive 'aa': %s\n", yytext); 
                                else printf("Length of string is not equal to 6: %s\n",yytext); return 2;}
[a-c]{0,6}bb[a-c]{0,4}    { if (strlen(yytext) == 6) printf("Valid string with consecutive 'bb': %s\n", yytext);
                                else printf("Length of string is not equal to 6: %s\n",yytext); return 1;}
.*                        { printf("Invalid string: %s\n", yytext); return 0;}
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
