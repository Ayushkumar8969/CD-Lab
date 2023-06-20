// ********* LEX Tool program to scan reserve word *****************//

%{
#include<stdio.h>
%}

letter[a-zA-Z_]

digit[0-9]

%%

(auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while)* {printf("\n%s is a keyword!",yytext);}

({letter}|{digit})({letter}|{digit})* {printf("\n%s is not a keyword",yytext);}

%%
int main()
 {
  	yylex();
 }
 int yywrap()
 {
  	return 0;
 }
