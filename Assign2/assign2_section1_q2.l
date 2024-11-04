/*lex program to check if the string starts with c and wnds with r and other chars or digits in between*/

/* Rules Section*/

%% 

c[a-zA-Z0-9]*r    { printf("Valid string"); return 1;}

.* {printf("invalid string"); return 0;}

%% 

int yywrap(void){} 

int main() 
{ 
	
	yylex(); 

	return 0; 
}