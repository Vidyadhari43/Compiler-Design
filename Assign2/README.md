Install lex/flex tool inorder to run this codes in this assignments <br>
Steps to run the code:
1) flex <lex_file_name>
2) gcc lex.yy.c
3) a.out 
4) Enter input in stdin(terminal) <br>
<p>yylex() by default takes input from stdin unless explicitly mentioned in yyin. <br>
For example, if you want to take input from any file, then write yyin=(file_pointer to the corresponding file)
</p>
