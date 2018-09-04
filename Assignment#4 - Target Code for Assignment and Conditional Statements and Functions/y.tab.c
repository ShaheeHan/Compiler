/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ex_4.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//#define YYSTYPE char*

int token_no=2;
//void print_temp();
char left[100][100];
char right[100][100];

char argument[100][100];
int arg_index=0;

int left_index=0;
int right_index=0;
//void print_comma_exprs(); 
char global_data[1000];
int newLabel=0;
char lev[10];
int label_no=1;

//variable array
char variable[100][10];
int var_index=0;

char token[100][10];
int token_index=0;
//stack pointer handler
int stk=0;//stack pointer
char stk_add[10];
//stack pointer handler


void print_str(char str[100])
{
	 printf("la $a0, %s\n",str);
    	 printf("li $v0, 4\n");
    	 printf("syscall\n");
}

void newline()
{
	printf("la $a0,newLine\n");
	printf("li $v0, 4\nsyscall\n");
}
void print_integer(char str[10])
{
	printf("li  $v0, 1\n");
	printf("lw $t0,%s\n",str);
	printf("add $a0, $t0, $zero\n");
	printf("syscall\n");	
}
void stk_to_str(int stkp)
{
	memset(stk_add,'\0',sizeof(stk_add));
	if(stkp>9)
	{
		int two=stkp/10;
		int one=stkp-two*10;
		stk_add[0]=two+'0';
		stk_add[1]=one+'0';
		stk_add[2]='\0';
				
	}
	else
	{
		stk_add[0]=stkp+'0';
		stk_add[1]='\0';
	
	}

}
int duplicate(char str[100])
{
	int i=0;
	for(i=0;i<var_index;i++)
	{
		if(strcmp(variable[i],str)==0)return 1;
	}
	return 0;

}

void substr_match(int len,char sub[10000],char mat[5])
{

	int l=len;
	int i=0,j=0;

	for(i=0;i<l-2;i++)
	{
		if(sub[i]==mat[0] && sub[i+1]==mat[1] && sub[i+2]==mat[2])
		{
			sub[i]=' ';
			sub[i+1]=' ';
			sub[i+2]=' ';	
		}
		
	}

}

void substr_match_jL0(int len,char sub[10000],char mat[5])
{

	int l=len;
	int i=0,j=0;

	for(i=0;i<l-3;i++)
	{
		if(sub[i]==mat[0] && sub[i+2]==mat[2] && sub[i+3]==mat[3])
		{
			sub[i]=' ';
			sub[i+2]=' ';
			sub[i+3]=' ';	
		}

	}


}


char label_array[100][10]={0};
int label_index=0;
void gen_label(char str1[10])
{
	memset(str1,'\0',sizeof(str1));
	str1[0]='L';
	if(label_no>9)
	{
		int two=label_no/10;
		int one=label_no-two*10;
		str1[1]=two+'0';
		str1[2]=one+'0';
		str1[3]='\0';
		label_no++;
				
	}
	else
	{
		str1[1]=label_no+'0';
		str1[2]='\0';
		label_no++;
	
	}
	strcpy(token[label_index],str1);
	label_index++;
}

void p(char* path)
{
	int i,l;
	l=strlen(path);
	printf("size of total length = %d\n",l);
	for(i=0;i<l;i++)
	{
		if(path[i]==';')
			printf("\n");
		else
			printf("%c",path[i]);
	}
	
	memset(global_data,0,sizeof(global_data));
}

void print_temp(char str2[])
{
	memset(str2,'\0',sizeof(str2));
	str2[0]='t';
	if(token_no>9)
	{
		int two=token_no/10;
		int one=token_no-two*10;
		str2[1]=two+'0';
		str2[2]=one+'0';
		str2[3]='\0';
		token_no++;
				
	}
	else
	{
		str2[1]=token_no+'0';
		str2[2]='\0';
		token_no++;
	
	}
	strcpy(token[token_index],str2);
	token_index++;
}
void print_comma_exprs()
{
	int in=0;
	for(in=0;in<left_index;in++)
	{
	 printf("%s = %s\n",left[in],right[in]);
	}
}
char TAC[10000];
int TAC_len=0;

void print_3ac()
{
	int i=0;
	for(i=0;i<TAC_len;i++)
	{
		printf("%c",TAC[i]);
	}
	printf("\n");
}


#line 281 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 216 "ex_4.y" /* yacc.c:355  */

	char id[10000];
	struct s
	{
		char true1[10];
		char false1[10];
		char next[10];
		char code[10000];
		char temp[10];
	} st;


#line 404 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 421 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  100

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   244,   244,   253,   260,   265,   271,   280,   286,   291,
     297,   307,   318,   347,   356,   367,   413,   421,   436,   464,
     489,   505,   516,   532,   555,   561,   568,   577,   584,   612,
     628,   645,   647,   653,   675,   677,   687,   693,   717,   722,
     744,   749,   767,   772,   797,   821,   845,   870,   895,   922,
     927,   943,   967,   993,   998,  1024,  1049,  1060,  1080,  1090,
    1102,  1110
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "REAL", "ID", "PLUS", "MINUS",
  "MUL", "DIV", "OPEN", "CLOSE", "ASSIGN", "SEMICOLON", "COMMA", "RETURN",
  "TRUE", "FALSE", "SOPEN", "SCLOSE", "NOT", "GREATER_EQ", "GREATER",
  "LESS", "LESS_EQ", "EQ", "NOT_EQ", "OR", "AND", "COLON", "THEN", "IF",
  "FI", "ELSE", "DO", "OD", "$accept", "result", "program", "stmts",
  "stmt", "selection", "iteration", "alts", "alt", "guard", "assignment",
  "vars", "subprogram", "exprs", "subprogramDecl", "heading", "args",
  "body", "returnStmt", "expr", "disjunction", "conjunction", "negation",
  "relation", "sum", "term", "factor", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF -44

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-44)))

#define YYTABLE_NINF -25

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -1,     3,     5,    24,    24,    17,   -44,     7,   -44,   -44,
     -44,   -44,     4,   -44,    14,    37,   -44,    23,   -44,   -44,
     -44,    66,    24,   -44,   -44,    56,   -20,   -44,    16,   -44,
      22,    26,   -44,   -44,     0,    69,   -44,   -21,   -44,    -1,
      48,    57,    -1,   -44,    53,    63,    24,    69,    64,   -44,
      24,   -44,    -1,    24,    24,    66,    66,    56,    56,    56,
      56,    56,    56,    66,    66,   -44,   -44,    67,    68,    70,
     -44,   -44,    30,    37,   -44,    70,   -44,   -44,     7,    26,
     -44,    69,    69,    32,    32,    32,    32,    32,    32,   -44,
     -44,    24,    24,    24,    62,   -44,    70,   -44,    70,   -44
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    22,     0,     0,     0,     0,     2,     3,     5,     7,
       8,     9,     0,    10,     0,    31,    24,     0,    56,    59,
      57,     0,     0,    60,    61,     0,     0,    13,     0,    16,
      35,    36,    38,    40,    42,    49,    53,     0,     1,     0,
       0,     0,     0,    27,    30,     0,    21,    50,     0,    41,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     6,    57,     0,    17,
      25,    23,    34,    31,    28,    19,    58,    14,    15,    37,
      39,    51,    52,    47,    48,    43,    44,    45,    46,    54,
      55,    20,     0,     0,     0,    29,    18,    26,    33,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -44,   -44,   -44,   -37,    46,   -44,   -44,    82,    38,   -44,
     -44,   -44,    47,   -43,   -44,   -44,    25,   -44,   -44,    -3,
     -44,    43,    45,    72,    33,   -19,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    26,    27,    28,
      11,    12,    17,    69,    13,    14,    45,    43,    94,    70,
      30,    31,    32,    33,    34,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      29,    29,    47,    75,     1,    72,    55,    56,    50,    50,
      16,     2,    51,    15,    65,    78,    40,    38,    41,    48,
      39,    57,    58,    59,    60,    61,    62,    18,    19,    20,
       3,    21,    42,     4,    22,    46,    81,    82,    55,    56,
      23,    24,    44,    39,    25,    93,    52,    29,    96,    53,
      98,    18,    19,    67,    54,    21,    89,    90,    22,    18,
      19,    20,    71,    21,    23,    24,    22,    73,    25,    18,
      19,    20,    23,    24,    74,    76,    22,    63,    64,   -24,
      91,    99,    23,    24,    92,    66,    37,    68,    77,    97,
      83,    84,    85,    86,    87,    88,    79,    49,    95,    80
};

static const yytype_uint8 yycheck[] =
{
       3,     4,    21,    46,     5,    42,     6,     7,    29,    29,
       5,    12,    32,    10,    35,    52,    12,     0,    14,    22,
      13,    21,    22,    23,    24,    25,    26,     3,     4,     5,
      31,     7,    18,    34,    10,    12,    55,    56,     6,     7,
      16,    17,     5,    13,    20,    15,    30,    50,    91,    27,
      93,     3,     4,     5,    28,     7,    63,    64,    10,     3,
       4,     5,     5,     7,    16,    17,    10,    14,    20,     3,
       4,     5,    16,    17,    11,    11,    10,     8,     9,    12,
      12,    19,    16,    17,    14,    39,     4,    40,    50,    92,
      57,    58,    59,    60,    61,    62,    53,    25,    73,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    12,    31,    34,    37,    38,    39,    40,    41,
      42,    46,    47,    50,    51,    10,     5,    48,     3,     4,
       5,     7,    10,    16,    17,    20,    43,    44,    45,    55,
      56,    57,    58,    59,    60,    61,    62,    43,     0,    13,
      12,    14,    18,    53,     5,    52,    12,    61,    55,    59,
      29,    32,    30,    27,    28,     6,     7,    21,    22,    23,
      24,    25,    26,     8,     9,    35,    40,     5,    48,    49,
      55,     5,    39,    14,    11,    49,    11,    44,    39,    57,
      58,    61,    61,    60,    60,    60,    60,    60,    60,    62,
      62,    12,    14,    15,    54,    52,    49,    55,    49,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    40,    40,
      40,    41,    42,    43,    43,    44,    45,    46,    46,    46,
      46,    46,    47,    47,    48,    49,    49,    50,    51,    52,
      52,    52,    53,    54,    54,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     3,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     5,     4,
       4,     3,     1,     3,     1,     1,     3,     2,     4,     3,
       1,     0,     4,     2,     0,     1,     1,     3,     1,     3,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     1,
       2,     3,     3,     1,     3,     3,     1,     1,     3,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 245 "ex_4.y" /* yacc.c:1646  */
    {
								
								int len=strlen((yyvsp[0].st).code);
								TAC_len=len;
								memset(TAC,0,sizeof(TAC));
								strcpy(TAC,(yyvsp[0].st).code);
								
							 }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 254 "ex_4.y" /* yacc.c:1646  */
    {
							
								strcpy((yyval.st).code,(yyvsp[0].st).code);
								
							}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 260 "ex_4.y" /* yacc.c:1646  */
    {
								printf("empty\n");
							}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 266 "ex_4.y" /* yacc.c:1646  */
    {
							
								strcpy((yyval.st).code,(yyvsp[0].st).code);
							
							}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 272 "ex_4.y" /* yacc.c:1646  */
    {
							
								strcat((yyvsp[-2].st).code,(yyvsp[0].st).code);
								strcpy((yyval.st).code,(yyvsp[-2].st).code);
							

							  }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 281 "ex_4.y" /* yacc.c:1646  */
    {
								
								strcpy((yyval.st).code,(yyvsp[0].st).code);
								
							  }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 287 "ex_4.y" /* yacc.c:1646  */
    {
								strcpy((yyval.st).code,(yyvsp[0].st).code);
								
							  }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 292 "ex_4.y" /* yacc.c:1646  */
    {
								
								strcpy((yyval.st).code,(yyvsp[0].st).code);
								//printf("ass out\n");
							  }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 298 "ex_4.y" /* yacc.c:1646  */
    {
								
								strcpy((yyval.st).code,"j exit\n");
								strcat((yyval.st).code,(yyvsp[0].st).code);
								
							  }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 308 "ex_4.y" /* yacc.c:1646  */
    {
	
								
								strcpy((yyval.st).code,(yyvsp[-1].st).code);
								strcat((yyval.st).code,"L0:\n");
	
								
							  }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 319 "ex_4.y" /* yacc.c:1646  */
    {
								int len=strlen((yyvsp[-1].st).code);
								char str[len+100];
								strcpy(str,(yyvsp[-1].st).code);
								int i=0;
								char mat[5]={0};
								strcpy(mat,(yyvsp[-1].st).false1);
								strcat(mat,":");
								substr_match(len,str,mat);
								memset(mat,0,sizeof(mat));
								strcpy(mat,"j L0");
								substr_match_jL0(len,str,mat);
								//
								char lv_begin[10];
								gen_label(lv_begin);

								strcpy((yyval.st).code,lv_begin);
								strcat((yyval.st).code,":\n");
								strcat((yyval.st).code,str);
								strcat((yyval.st).code,"j ");
								strcat((yyval.st).code,lv_begin);
								strcat((yyval.st).code,"\n");
								strcat((yyval.st).code,(yyvsp[-1].st).false1);
								strcat((yyval.st).code,":\n");
							}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 348 "ex_4.y" /* yacc.c:1646  */
    { 

								strcpy((yyval.st).code,(yyvsp[0].st).code);
								strcpy((yyval.st).true1,(yyvsp[0].st).true1);
								strcpy((yyval.st).false1,(yyvsp[0].st).false1);
						
								strcpy((yyval.st).temp,(yyvsp[0].st).temp);//temp
							  }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 357 "ex_4.y" /* yacc.c:1646  */
    {
								
								strcat((yyvsp[-2].st).code,(yyvsp[0].st).code);	
								strcpy((yyval.st).code,(yyvsp[-2].st).code);
								strcat((yyval.st).code," j L0\n");
								
								strcpy((yyval.st).temp,(yyvsp[0].st).temp);//temp	

							}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 368 "ex_4.y" /* yacc.c:1646  */
    {
								char lv_t[10]={0};
								memset(lv_t,0,sizeof(lv_t));
								gen_label(lv_t);
		
								char lv_f[10]={0};
								memset(lv_f,0,sizeof(lv_f));
								gen_label(lv_f);
	
								strcpy((yyval.st).code,(yyvsp[-2].st).code);
	
								strcat((yyval.st).code,"li $t5,1\n");

								strcat((yyval.st).code,"beq ");
								strcat((yyval.st).code,(yyvsp[-2].st).temp);
								strcat((yyval.st).code,",");
								strcat((yyval.st).code," $t5 , ");
								strcat((yyval.st).code,lv_t);	
								strcat((yyval.st).code,"\n");

								strcat((yyval.st).code,"j ");
								strcat((yyval.st).code,lv_f);
								strcat((yyval.st).code,"\n");

								strcat((yyval.st).code,lv_t);//true label
								strcat((yyval.st).code,":\n");
	
								strcat((yyval.st).code,(yyvsp[0].st).code);	
								strcat((yyval.st).code,"\n");

								strcat((yyval.st).code,"j L0\n");
	
								strcat((yyval.st).code,lv_f);
								strcat((yyval.st).code,":\n");	
	

								strcpy((yyval.st).true1,lv_t);

								strcpy((yyval.st).false1,lv_f);


								strcpy((yyval.st).temp,(yyvsp[-2].st).temp);//temp

							}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 414 "ex_4.y" /* yacc.c:1646  */
    {

								strcpy((yyval.st).code,(yyvsp[0].st).code);
								strcpy((yyval.st).temp,(yyvsp[0].st).temp);
								
							}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 422 "ex_4.y" /* yacc.c:1646  */
    {  
								
								strcpy((yyval.st).code,(yyvsp[0].st).code);
								strcat((yyval.st).code,"move $t0,");
								strcat((yyval.st).code,(yyvsp[0].st).temp);
								strcat((yyval.st).code,"\n");
	
								strcat((yyval.st).code,"sw $t0,");
								strcat((yyval.st).code,(yyvsp[-2].st).code);
								strcat((yyval.st).code,"\n");
								right_index=right_index-1;
								left_index=left_index-1;
							
							}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 437 "ex_4.y" /* yacc.c:1646  */
    {

								strcpy((yyval.st).code,"sw $fp,0($sp)\n");
								strcat((yyval.st).code,"addiu $sp,$sp,-4\n");
								stk=stk+4;
								int ri=right_index;
								int i=ri-1;
								for(;i>=0;i--)
								{
									strcat((yyval.st).code,right[i]);
									strcat((yyval.st).code,"sw $t0,0($sp)\n");
									strcat((yyval.st).code,"addiu $sp,$sp,-4\n");
									stk=stk+4;
								}
								strcat((yyval.st).code,"jal ");
								strcat((yyval.st).code,(yyvsp[-2].st).code);
								strcat((yyval.st).code,"\n");
								
								
								
								strcat((yyval.st).code,"sw $v1,"); 
								strcat((yyval.st).code,(yyvsp[-4].st).code);
								strcat((yyval.st).code,"\n");
							
	
							}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 465 "ex_4.y" /* yacc.c:1646  */
    {
	
								strcpy((yyval.st).code,"sw $fp,0($sp)\n");
								strcat((yyval.st).code,"addiu $sp,$sp,-4\n");
								stk=stk+4;
								int ri=right_index;
								int i=ri-1;
								for(;i>=0;i--)
								{
									strcat((yyval.st).code,right[i]);
									strcat((yyval.st).code,"sw $t0,0($sp)\n");
									strcat((yyval.st).code,"addiu $sp,$sp,-4\n");
									stk=stk+4;
								}
								strcat((yyval.st).code,"jal ");
								strcat((yyval.st).code,(yyvsp[-2].st).code);
								strcat((yyval.st).code,"\n");
	
							
								right_index=right_index-1;
							
	
							 }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 490 "ex_4.y" /* yacc.c:1646  */
    { 
								strcpy((yyval.st).code,"sw $fp,0($sp)\n");
								strcat((yyval.st).code,"addiu $sp,$sp,-4\n");
								stk=stk+4;
								strcat((yyval.st).code,"jal ");
								strcat((yyval.st).code,(yyvsp[-1].st).code);
								strcat((yyval.st).code,"\n");
								//return
								strcat((yyval.st).code,"sw $v1,"); 
								strcat((yyval.st).code,(yyvsp[-3].st).code);
								strcat((yyval.st).code,"\n");
								right_index=right_index-1;
								left_index=left_index-1;

     						}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 506 "ex_4.y" /* yacc.c:1646  */
    {
								strcpy((yyval.st).code,"sw $fp,0($sp)\n");
								strcat((yyval.st).code,"addiu $sp,$sp,-4\n");
								stk=stk+4;
								strcat((yyval.st).code,"jal ");
								strcat((yyval.st).code,(yyvsp[-1].st).code);
								strcat((yyval.st).code,"\n");
							}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 517 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy(left[left_index],(yyvsp[0].id)); 
							left_index++;
							strcpy((yyval.st).code,(yyvsp[0].id));
							strcpy((yyval.st).temp,(yyvsp[0].id));
							int check=duplicate((yyvsp[0].id));
							if(check==0)
							{
								strcpy(variable[var_index],(yyvsp[0].id));
								var_index++;	
	
							}

							 
						 }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 533 "ex_4.y" /* yacc.c:1646  */
    {
							char str[100];

							strcpy(str,"lw $a0,");
							strcat(str,(yyvsp[0].id));
							strcat(str,"\n"); 	
							strcat(str,"move $s7,$a0\n");
							strcpy(left[left_index],(yyvsp[0].id)); 
							left_index++; 
							strcpy((yyval.st).code,str);
							strcpy((yyval.st).temp,"$s7");

							int check=duplicate((yyvsp[0].id));
							if(check==0)
							{
								strcpy(variable[var_index],(yyvsp[0].id));
								var_index++;	
	
							}

						}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 556 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[0].id));
						  }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 562 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy(right[right_index],(yyvsp[0].st).code); 
							right_index++;
							strcpy((yyval.st).code,(yyvsp[0].st).code);
							strcpy((yyval.st).temp,(yyvsp[0].st).temp); 
						  }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 569 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy(right[right_index],(yyvsp[0].st).code); 
							right_index++;
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcpy((yyval.st).temp,(yyvsp[0].st).temp); 
						  }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 578 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[-1].st).code);
							strcat((yyval.st).code,(yyvsp[0].st).code);	

						  }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 585 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[-3].id));
							strcat((yyval.st).code,":\n");
							strcat((yyval.st).code,"move $fp,$sp\n");
							strcat((yyval.st).code,"sw $ra,0($sp)\n");
							strcat((yyval.st).code,"addiu $sp,$sp,-4\n");
							stk=stk+4;
							int i=0;
							
							int ai=arg_index-1;
							int stk_p=4;
							for(i=ai;i>=0;i--)
							{
								stk_to_str(stk_p);
								strcat((yyval.st).code,"lw $t0,");
								strcat((yyval.st).code,stk_add);
								strcat((yyval.st).code,"($fp)\n");
								stk_p=stk_p+4;
							
								strcat((yyval.st).code,"sw $t0,");
								strcat((yyval.st).code,argument[i]);
								strcat((yyval.st).code,"\n");
							}
		
						 }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 613 "ex_4.y" /* yacc.c:1646  */
    {

							strcpy(argument[arg_index],(yyvsp[-2].id)); 
							arg_index++;
							strcpy((yyval.st).code,(yyvsp[-2].id));

							int check=duplicate((yyvsp[-2].id));
							if(check==0)
							{
								strcpy(variable[var_index],(yyvsp[-2].id));
								var_index++;	
	
							}

						  }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 629 "ex_4.y" /* yacc.c:1646  */
    {
							

							int check=duplicate((yyvsp[0].id));
							if(check==0)
							{
								strcpy(variable[var_index],(yyvsp[0].id));
								var_index++;	
	
							}
							char str[100];
							
							strcpy(argument[arg_index],(yyvsp[0].id)); 
							arg_index++;
							strcpy((yyval.st).code,(yyvsp[0].id));	
  						  }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 645 "ex_4.y" /* yacc.c:1646  */
    {}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 648 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,(yyvsp[-1].st).code);	
						  }
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 654 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"lw $ra, 4($sp)\n");
							stk_to_str(stk);
							strcat((yyval.st).code,"addi $sp,$sp,");
							strcat((yyval.st).code,stk_add);
							strcat((yyval.st).code,"\n");
							
							if(left_index>0)
							{
								strcat((yyval.st).code,"move $v1,");
								strcat((yyval.st).code,(yyvsp[0].st).temp);
								strcat((yyval.st).code,"\n");	
	
							}
							strcat((yyval.st).code,"jr $ra\n");	
							
							right_index=right_index-1;
							left_index=left_index-1;

						}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 675 "ex_4.y" /* yacc.c:1646  */
    {}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 678 "ex_4.y" /* yacc.c:1646  */
    { 

	
							strcpy((yyval.st).code,(yyvsp[0].st).code);
							strcpy((yyval.st).temp,(yyvsp[0].st).temp);
	
							 
						}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 688 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code,(yyvsp[0].st).code);
							strcpy((yyval.st).temp,(yyvsp[0].st).temp); 

						  }
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 694 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $s0,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");

							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $s1,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"or $t3,$s0,$s1\n");

							
							char temp[10];
							
							strcpy(temp,"$s7");
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);

						  }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 718 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code,(yyvsp[0].st).code); 
							strcpy((yyval.st).temp,(yyvsp[0].st).temp);
						}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 723 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $t2,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $t3,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"and $t3,$t2,$t3\n");
	
							char temp[10];
							
							strcpy(temp,"$s7");
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);
						}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 745 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code,(yyvsp[0].st).code) ; 
							strcpy((yyval.st).temp,(yyvsp[0].st).temp) ;
						  }
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 750 "ex_4.y" /* yacc.c:1646  */
    { 

							strcpy((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"neg $t4,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);

							char temp[10];

							strcpy(temp,"$s7");	
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t4\n");
							strcpy((yyval.st).temp,temp);

						 }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 768 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code,(yyvsp[0].st).code); 
							strcpy((yyval.st).temp,(yyvsp[0].st).temp); 
						  }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 773 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $a2,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $a3,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"slt $t3,$a2,$a3\n");
	

							char temp[10];

							strcpy(temp,"$s7");	
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);
	
		
						}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 798 "ex_4.y" /* yacc.c:1646  */
    {

							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $s6,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $t9,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"sle $t3,$s6,$t9\n");
	
							//strcpy($$.temp,"$t3");
							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);

						}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 822 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $t8,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $t9,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"seq $t3,$t8,$t9\n");
	

							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);

	
						}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 846 "ex_4.y" /* yacc.c:1646  */
    { 

							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $t6,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $t7,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"sne $t3,$t6,$t7\n");
	
							//strcpy($$.temp,"$t3");
							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);	

							 
						}
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 871 "ex_4.y" /* yacc.c:1646  */
    {

							strcpy((yyval.st).code,(yyvsp[-2].st).code);//lw dest,src
							strcat((yyval.st).code,"move $t5,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $t6,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"sge $t3,$t5,$t6\n");
	
							//strcpy($$.temp,"$t3");

							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");	
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);
	
						}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 896 "ex_4.y" /* yacc.c:1646  */
    { 	
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $a2,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $a3,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"sgt $t3,$a2,$a3\n");
	
							
							char temp[10]={0};
							//print_temp(temp);
							strcpy(temp,"$s7");
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);


						 
						}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 923 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code, (yyvsp[0].st).code);
							strcpy((yyval.st).temp, (yyvsp[0].st).temp); 
						}
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 928 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"neg $t4,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);

							char temp[10];
							strcpy(temp,"$s7");

							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t4\n");
							strcpy((yyval.st).temp,temp);	
	
	
						}
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 944 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $a0,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $a1,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"add $t3,$a0,$a1\n");
	
							char temp[10];

							strcpy(temp,"$s7");	
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);



						}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 968 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $s5,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $s6,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"sub $t3,$s5,$s6\n");
	

							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");	
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);

						}
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 994 "ex_4.y" /* yacc.c:1646  */
    { 
							strcpy((yyval.st).code, (yyvsp[0].st).code);
							strcpy((yyval.st).temp, (yyvsp[0].st).temp);
						}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 999 "ex_4.y" /* yacc.c:1646  */
    {

							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $s3,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $s4,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"mul $t3,$s3,$s4\n");
	

							char temp[10];

							strcpy(temp,"$s7");	
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");
							strcpy((yyval.st).temp,temp);


	
						}
#line 2515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1025 "ex_4.y" /* yacc.c:1646  */
    {
							strcpy((yyval.st).code,(yyvsp[-2].st).code);
							strcat((yyval.st).code,"move $s1,");		
							strcat((yyval.st).code,(yyvsp[-2].st).temp);
							strcat((yyval.st).code,"\n");
	
							strcat((yyval.st).code,(yyvsp[0].st).code);
							strcat((yyval.st).code,"move $s2,");
							strcat((yyval.st).code,(yyvsp[0].st).temp);
							strcat((yyval.st).code,"\n");
							strcat((yyval.st).code,"div $t3,$s1,$s2\n");
	
							char temp[10];

							strcpy(temp,"$s7");	
							strcat((yyval.st).code,"move ");
							strcat((yyval.st).code,temp);
							strcat((yyval.st).code,",$t3\n");

							strcpy((yyval.st).temp,temp);
	
						}
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1050 "ex_4.y" /* yacc.c:1646  */
    {
							char str[100];
							strcpy(str,"li $t0,");
							strcat(str,(yyvsp[0].id));
							strcat(str,"\n");

							strcpy((yyval.st).code,str);
							strcpy((yyval.st).temp,"$t0");	
		
						}
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1061 "ex_4.y" /* yacc.c:1646  */
    { 

							char str[100];
							strcpy(str,"lw $t0,");
							strcat(str,(yyvsp[0].id));
							strcat(str,"\n");

							strcpy((yyval.st).code,str);
							strcpy((yyval.st).temp,"$t0");
	
							int check=duplicate((yyvsp[0].id));
							if(check==0)
							{
								strcpy(variable[var_index],(yyvsp[0].id));
								var_index++;	
	
							}
							 
						}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1081 "ex_4.y" /* yacc.c:1646  */
    { 

							char str[100];
							//cgen(str,$2.code);
	
							strcpy((yyval.st).code,(yyvsp[-1].st).code);
							strcpy((yyval.st).temp,(yyvsp[-1].st).temp);	
							 
						}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1091 "ex_4.y" /* yacc.c:1646  */
    { 
							char str[100];
							strcpy(str,"li.s $f0,");
							strcat(str,(yyvsp[0].id));
							strcat(str,"\n");
							strcpy((yyval.st).code,str);
							strcpy((yyval.st).temp,"$f0");
		
	
							 
						}
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1103 "ex_4.y" /* yacc.c:1646  */
    { 

							char str[100];
							strcpy(str,"li $t0,1\n");
							strcpy((yyval.st).code,str);
							strcpy((yyval.st).temp,"$t0");		
						}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1110 "ex_4.y" /* yacc.c:1646  */
    {
							char str[100];
							strcpy(str,"li $t0,0\n");
							strcpy((yyval.st).code,str);
							strcpy((yyval.st).temp,"$t0");	
	
		
						}
#line 2636 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2640 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1120 "ex_4.y" /* yacc.c:1906  */

extern int yylex();
extern int yyparse();
extern FILE *yyin;

main()
{
	FILE *myfile = fopen("input.txt", "r");

	if (!myfile) {
		printf("File error\n");
		return -1;
	}
	yyin = myfile;
	
	do {
		yyparse();
	} while (!feof(yyin));
	puts("");
	puts("");
	puts("");
	print_3ac();	

}

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}
