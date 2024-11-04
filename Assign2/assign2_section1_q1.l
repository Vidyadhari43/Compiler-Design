/*lex program to check if there are atleast six ones*/

/* Rules Section*/
%% 
(0)*1(0)*1(0)*1(0)*1(0)*1(0)*1(0|1)* {printf("String Contains atleast six ones");return 1;} 
.*	{printf("String Doesnot Contains atleast six ones");return 0;}

%% 

int yywrap(void){} 

int main() 
{ 
	
	yylex(); 

	return 0; 
}