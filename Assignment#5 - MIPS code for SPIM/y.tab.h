/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    REAL = 259,
    ID = 260,
    PLUS = 261,
    MINUS = 262,
    MUL = 263,
    DIV = 264,
    OPEN = 265,
    CLOSE = 266,
    ASSIGN = 267,
    SEMICOLON = 268,
    COMMA = 269,
    RETURN = 270,
    TRUE = 271,
    FALSE = 272,
    SOPEN = 273,
    SCLOSE = 274,
    NOT = 275,
    GREATER_EQ = 276,
    GREATER = 277,
    LESS = 278,
    LESS_EQ = 279,
    EQ = 280,
    NOT_EQ = 281,
    OR = 282,
    AND = 283,
    COLON = 284,
    THEN = 285,
    IF = 286,
    FI = 287,
    ELSE = 288,
    DO = 289,
    OD = 290
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define REAL 259
#define ID 260
#define PLUS 261
#define MINUS 262
#define MUL 263
#define DIV 264
#define OPEN 265
#define CLOSE 266
#define ASSIGN 267
#define SEMICOLON 268
#define COMMA 269
#define RETURN 270
#define TRUE 271
#define FALSE 272
#define SOPEN 273
#define SCLOSE 274
#define NOT 275
#define GREATER_EQ 276
#define GREATER 277
#define LESS 278
#define LESS_EQ 279
#define EQ 280
#define NOT_EQ 281
#define OR 282
#define AND 283
#define COLON 284
#define THEN 285
#define IF 286
#define FI 287
#define ELSE 288
#define DO 289
#define OD 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 219 "ex_5.y" /* yacc.c:1909  */

	char id[10000];
	struct s
	{
		char true1[10];
		char false1[10];
		char next[10];
		char code[10000];
		char temp[10];
	} st;
	//ETYPE eval; 

#line 137 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
