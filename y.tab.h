/* A Bison parser, made by GNU Bison 2.7.1.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     NUMBER = 259,
     PLUS = 260,
     BMINUS = 261,
     MULTIPLY = 262,
     OP = 263,
     CP = 264,
     AND = 265,
     OR = 266,
     DO = 267,
     COMMA = 268,
     DIVIDE = 269,
     MOD = 270,
     VAR = 271,
     FUNC_NAME = 272,
     PERIOD = 273,
     EQ = 274,
     FOR = 275,
     THEN = 276,
     IF = 277,
     FI = 278,
     RETURN = 279,
     MAIN = 280,
     END = 281,
     BREAK = 282,
     CONTINUE = 283,
     SRIGHT = 284,
     SLEFT = 285,
     BAND = 286,
     BOR = 287,
     BXOR = 288,
     BITCOMPLEMENT = 289,
     LE = 290,
     GE = 291,
     L = 292,
     G = 293,
     NOT = 294,
     NE = 295,
     EE = 296,
     ELSE = 297,
     DEC = 298,
     INC = 299,
     UMINUS = 300,
     OUT = 301,
     IN = 302,
     STRING = 303,
     LOOP = 304,
     TILL = 305,
     WITH = 306
   };
#endif
/* Tokens.  */
#define INT 258
#define NUMBER 259
#define PLUS 260
#define BMINUS 261
#define MULTIPLY 262
#define OP 263
#define CP 264
#define AND 265
#define OR 266
#define DO 267
#define COMMA 268
#define DIVIDE 269
#define MOD 270
#define VAR 271
#define FUNC_NAME 272
#define PERIOD 273
#define EQ 274
#define FOR 275
#define THEN 276
#define IF 277
#define FI 278
#define RETURN 279
#define MAIN 280
#define END 281
#define BREAK 282
#define CONTINUE 283
#define SRIGHT 284
#define SLEFT 285
#define BAND 286
#define BOR 287
#define BXOR 288
#define BITCOMPLEMENT 289
#define LE 290
#define GE 291
#define L 292
#define G 293
#define NOT 294
#define NE 295
#define EE 296
#define ELSE 297
#define DEC 298
#define INC 299
#define UMINUS 300
#define OUT 301
#define IN 302
#define STRING 303
#define LOOP 304
#define TILL 305
#define WITH 306



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 44 "c.y"

	int number;
	char *var_name;


/* Line 2053 of yacc.c  */
#line 165 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
