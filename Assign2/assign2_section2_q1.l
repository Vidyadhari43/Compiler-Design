%{
#include <stdio.h>
#include <string.h>
%}

/* Rules Section */
%%
[-]?([^0-9\n\t"'.-])*[0-9]([^\n\t"'.-])* { printf("Integer\n");  return 1;}
[-]?[0-9]+[.][0-9]+ { printf("Float\n"); return 1; }
[']{1}[^'"]['] { printf("Character constant\n"); return 1; }
["]{1}[^"]*["] {printf("String constant\n"); return 1;}
.* { printf("Invalid Input\n"); return -1; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("return value: %d",yylex());
    return 0;
}
