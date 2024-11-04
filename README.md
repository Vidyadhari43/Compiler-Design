Some Important points: <br>
Lex/flex file structure/format: <br>
%{ <br>
c code that will be inculded directly into lex.yy.c <br>
%} <br>
%% <br>
(also known as lex function/ lex rules)
Regular Expression-1 {Action1} <br>
.<br>
.<br>
Regular Expression-n {Actionn} <br>
%% <br>

/* Subroutines section <br>
should define int main() and int yywrap(void) as per requirements <br>
optional section<br>
*/ <br>
<p>
Flow of excution of lex file:<br>
When a Lex program runs, the flow of execution proceeds as follows:

Start: The main function (either in the Lex file or an external C file) calls yylex(), which starts the scanning process.

Scanning Text: yylex() reads the input text, one token at a time, to match it with the rules defined in the rules section.

Pattern Matching: Lex checks each pattern against the input text. If a pattern matches, Lex performs the action specified in the {} following that pattern.

yytext contains the matched text of the most recent token, which can be used within the actions.
End of File: When Lex reaches the end of the file, it calls yywrap(). By default, yywrap() returns 1, indicating the end of input, but it can be overridden for custom behavior.

Completion: yylex() stops, and the program either finishes execution or continues as programmed in main() or other functions.
</p>
