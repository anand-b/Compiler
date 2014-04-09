/*
@author "Anand.B & Ganesh Prabu.R"
@Date Modified "06/04/2014"
*/
%{
	#include<stdio.h>
	#include<string.h>
	#include "y.tab.h"
	extern YYSTYPE yylval;
	int line=1;
%}
%%
[#][^#^\r^\n.]*[#]								{;}
[#][^\r\n.]*									{;}
[ \t\r\f]										{;}
[\n]											{line++;}
"till"											{return TILL;}
"with"											{return WITH;}
"do"											{return DO;}
"loop"											{return LOOP;}
"out"											{return OUT;}
"in"											{return IN;}
"then"											{return THEN;}
"if"											{return IF;}
"else"											{return ELSE;}
"finish"										{return END;}
"int"											{return INT;}
"break"											{return BREAK;}
"continue"										{return CONTINUE;}
"fi"											{return FI;}
"go"											{return MAIN;}
"return"										{return RETURN;}
"++"											{return INC;}
"--"											{return DEC;}
"!"												{return NOT;}
"~"												{return BITCOMPLEMENT;}
"+"												{return PLUS;}
"-"												{return BMINUS;}	
"*"												{return MULTIPLY;}
"/"												{return DIVIDE;}
"%"												{return MOD;}
"="												{return EQ;}
","												{return COMMA;}
">>"											{return SRIGHT;}
"<<"											{return SLEFT;}
"<="											{return LE;}
">="											{return GE;}
"<"												{return L;}
">"												{return G;}
"!="											{return NE;}
"=="											{return EE;}
"$"												{return PERIOD;}
"("												{return OP;}
")"												{return CP;}
"&&"											{return AND;}
"||"											{return OR;}
"&"												{return BAND;}
"|"												{return BOR;}
"^"												{return BXOR;}
0|[1-9][0-9]*		 	 						{yylval.number=atoi(yytext);
												 return NUMBER;
												}
[a-z][a-z0-9]* 									{yylval.var_name=strdup(yytext);return VAR;}
[A-Z]+											{return FUNC_NAME;}
[\"][^\".]*[\"]									{
												yytext[strlen(yytext)-1]='\r';
												yylval.var_name=strdup(yytext+1);
												return STRING;
												}
%%
