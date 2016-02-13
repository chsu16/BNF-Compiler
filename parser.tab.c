/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

// Dummy parser for scanner project.

#include "lyutils.h"
#include "astree.h"
#include <assert.h>

#line 74 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_VOID = 258,
    TOK_BOOL = 259,
    TOK_CHAR = 260,
    TOK_INT = 261,
    TOK_STRING = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_RETURN = 266,
    TOK_STRUCT = 267,
    TOK_FALSE = 268,
    TOK_TRUE = 269,
    TOK_NULL = 270,
    TOK_NEW = 271,
    TOK_ARRAY = 272,
    TOK_EQ = 273,
    TOK_NE = 274,
    TOK_LT = 275,
    TOK_LE = 276,
    TOK_GT = 277,
    TOK_GE = 278,
    TOK_IDENT = 279,
    TOK_INTCON = 280,
    TOK_CHARCON = 281,
    TOK_STRINGCON = 282,
    TOK_FIELDS = 283,
    TOK_FIELDDECL = 284,
    TOK_BASETYPE = 285,
    TOK_FUNCTION = 286,
    TOK_PROTOTYPE = 287,
    TOK_IDENTDECL = 288,
    TOK_PARAM = 289,
    TOK_DECLID = 290,
    TOK_VARDECL = 291,
    TOK_RETURNVOID = 292,
    TOK_NEWSTRING = 293,
    TOK_EXPRLIST = 294,
    TOK_INDEX = 295,
    TOK_BLOCK = 296,
    TOK_CALL = 297,
    TOK_IFELSE = 298,
    TOK_INITDECL = 299,
    TOK_POS = 300,
    TOK_NEG = 301,
    TOK_NEWARRAY = 302,
    TOK_TYPEID = 303,
    TOK_FIELD = 304,
    TOK_ORD = 305,
    TOK_CHR = 306,
    TOK_ROOT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 178 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   603

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,     2,     2,    58,     2,     2,
      63,    64,    56,    54,    68,    55,    62,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    66,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,    65,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    40,    40,    42,    43,    44,    45,    46,    47,    50,
      52,    53,    55,    56,    58,    59,    60,    61,    62,    63,
      65,    67,    68,    69,    71,    72,    75,    76,    77,    79,
      80,    82,    83,    84,    85,    86,    87,    89,    91,    93,
      94,    96,    97,    99,   100,   101,   102,   103,   104,   105,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   120,   121,   122,   123,   124,   126,   127,   128,
     130,   132,   133,   134,   136,   137,   138,   140,   141,   142,
     143,   144,   145
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_BOOL", "TOK_CHAR",
  "TOK_INT", "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_RETURN",
  "TOK_STRUCT", "TOK_FALSE", "TOK_TRUE", "TOK_NULL", "TOK_NEW",
  "TOK_ARRAY", "TOK_EQ", "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE",
  "TOK_IDENT", "TOK_INTCON", "TOK_CHARCON", "TOK_STRINGCON", "TOK_FIELDS",
  "TOK_FIELDDECL", "TOK_BASETYPE", "TOK_FUNCTION", "TOK_PROTOTYPE",
  "TOK_IDENTDECL", "TOK_PARAM", "TOK_DECLID", "TOK_VARDECL",
  "TOK_RETURNVOID", "TOK_NEWSTRING", "TOK_EXPRLIST", "TOK_INDEX",
  "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE", "TOK_INITDECL", "TOK_POS",
  "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID", "TOK_FIELD", "TOK_ORD",
  "TOK_CHR", "TOK_ROOT", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'",
  "'['", "']'", "'.'", "'('", "')'", "'}'", "';'", "'{'", "','", "$accept",
  "start", "program", "structdef", "fields", "fielddecl", "basetype",
  "function", "prototype", "identdecl", "block", "state", "statement",
  "vardecl", "while", "ifelse", "return", "expr", "binop", "unop",
  "allocator", "call", "exprlist", "variable", "constant", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    61,    43,    45,    42,    47,    37,    33,
      91,    93,    46,    40,    41,   125,    59,   123,    44
};
# endif

#define YYPACT_NINF -58

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define YYTABLE_NINF -20

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -58,     4,   114,   -58,   -48,   -58,   -58,   -58,   -58,   -58,
     -34,    -7,    36,   -18,   -58,   -58,   -58,    21,    -8,   -58,
     -58,   -58,   315,   315,   315,   315,   315,   315,   -58,   179,
     -58,    13,   -58,   -22,   -58,   244,   -58,   -58,   -58,   -58,
     -58,   326,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     315,   315,    -6,   -58,   375,    12,    17,    19,    38,   315,
     -57,   -57,   -14,   -14,   -57,   403,   -58,    47,   -58,    65,
     -58,   315,    29,   -10,   -58,   -58,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,    77,
     -58,   450,   462,   -58,   -58,   315,    46,   315,   541,    24,
     -58,   -58,   389,   -58,   -58,    30,    29,    49,    49,    49,
      49,    49,    49,   541,   -14,   -14,   -57,   -57,   -57,   521,
     -58,   309,   309,    16,   474,   -58,   531,   -58,   315,   -58,
     -58,   -58,   -58,   122,   -58,   -58,    57,    60,   -58,   -58,
     541,   309,   -58,   108,   -58,   -58,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    14,    15,    16,    17,    18,
       0,     0,     0,     0,    80,    81,    82,     0,    74,    77,
      78,    79,     0,     0,     0,     0,     0,     0,    28,     0,
       3,     0,     4,     0,    31,     0,     5,    32,    33,    34,
      35,     0,    43,    44,    45,    46,    48,    49,     6,     7,
       0,     0,    74,    41,     0,     0,    18,    19,     0,    73,
      65,    66,    62,    63,    64,     0,    27,     0,    30,     0,
      24,     0,    23,     0,    26,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,    42,    11,     0,     0,     0,    72,     0,
      47,    25,     0,    19,    22,     0,     0,    51,    52,    53,
      54,    55,    56,    50,    60,    61,    57,    58,    59,     0,
      76,     0,     0,     0,     0,    67,     0,    70,     0,    37,
      20,    21,    75,    39,    38,     9,     0,     0,    68,    69,
      71,     0,    10,     0,    13,    40,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,   -58,   -15,   -58,   -58,     6,
      28,   -58,   -28,   -58,   -58,   -58,   -58,   -12,   -58,   -58,
     -58,   -58,   -58,   -58,   -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    30,   123,   136,    31,    32,    73,    67,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    99,    46,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    68,    58,    88,     3,    89,    55,    75,    33,   -19,
      60,    61,    62,    63,    64,    65,   -19,    48,    49,     5,
       6,     7,     8,     9,     5,     6,     7,     8,    56,    50,
      69,    71,     5,     6,     7,     8,     9,    70,    91,    92,
     103,    72,    85,    86,    87,    57,    88,    98,    89,    14,
      15,    16,    17,   103,   105,    59,    51,    59,   106,   102,
      52,    19,    20,    21,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   143,   104,    94,
      95,   135,    96,   124,   144,   126,    22,    23,   127,   101,
      24,    25,   128,   133,   134,    26,    28,    29,    97,    27,
      71,   120,    53,    83,    84,    85,    86,    87,   137,    88,
     125,    89,   131,   145,    -2,     4,   140,     5,     6,     7,
       8,     9,    10,   142,    11,    12,    13,    14,    15,    16,
      17,   141,   146,   130,     0,     0,     0,     0,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,     0,     0,    24,    25,
       0,     0,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,     5,     6,     7,     8,     9,    10,     0,    11,
      12,     0,    14,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,     0,     0,    24,    25,     0,     0,     0,    26,     0,
       0,     0,    27,     0,    66,    28,    29,     5,     6,     7,
       8,     9,    10,     0,    11,    12,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,     0,     0,    24,    25,
       0,     0,     0,    26,     0,     0,     0,    27,     0,    74,
      28,    29,     5,     6,     7,     8,     9,    10,     0,    11,
      12,     0,    14,    15,    16,    17,     0,     0,    14,    15,
      16,    17,     0,    18,    19,    20,    21,     0,     0,    52,
      19,    20,    21,     0,    76,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,     0,     0,    24,    25,    22,    23,     0,    26,    24,
      25,     0,    27,     0,    26,    28,    29,     0,    27,    82,
      83,    84,    85,    86,    87,     0,    88,     0,    89,     0,
       0,     0,    90,    76,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,     0,    82,    83,
      84,    85,    86,    87,     0,    88,     0,    89,     0,     0,
       0,    93,    82,    83,    84,    85,    86,    87,     0,    88,
       0,    89,     0,     0,     0,   129,    82,    83,    84,    85,
      86,    87,     0,    88,     0,    89,     0,   100,    76,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,     0,
      88,     0,    89,     0,   121,    82,    83,    84,    85,    86,
      87,     0,    88,     0,    89,     0,   122,    82,    83,    84,
      85,    86,    87,     0,    88,     0,    89,     0,   138,    76,
      77,    78,    79,    80,    81,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
       0,    88,   132,    89,    82,    83,    84,    85,    86,    87,
       0,    88,   139,    89,    82,    83,    84,    85,    86,    87,
       0,    88,     0,    89
};

static const yytype_int16 yycheck[] =
{
      12,    29,    17,    60,     0,    62,    24,    35,     2,    17,
      22,    23,    24,    25,    26,    27,    24,    65,    66,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    63,
      17,    53,     3,     4,     5,     6,     7,    24,    50,    51,
      24,    63,    56,    57,    58,    24,    60,    59,    62,    13,
      14,    15,    16,    24,    64,    63,    63,    63,    68,    71,
      24,    25,    26,    27,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    17,    72,    67,
      63,    65,    63,    95,    24,    97,    50,    51,    64,    24,
      54,    55,    68,   121,   122,    59,    66,    67,    60,    63,
      53,    24,    66,    54,    55,    56,    57,    58,   123,    60,
      64,    62,   106,   141,     0,     1,   128,     3,     4,     5,
       6,     7,     8,    66,    10,    11,    12,    13,    14,    15,
      16,     9,    24,   105,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    63,    -1,    -1,
      66,    67,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    63,    -1,    65,    66,    67,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    -1,    54,    55,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    63,    -1,    65,
      66,    67,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    14,    15,    16,    -1,    -1,    13,    14,
      15,    16,    -1,    24,    25,    26,    27,    -1,    -1,    24,
      25,    26,    27,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    54,    55,    50,    51,    -1,    59,    54,
      55,    -1,    63,    -1,    59,    66,    67,    -1,    63,    53,
      54,    55,    56,    57,    58,    -1,    60,    -1,    62,    -1,
      -1,    -1,    66,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    -1,    53,    54,
      55,    56,    57,    58,    -1,    60,    -1,    62,    -1,    -1,
      -1,    66,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    62,    -1,    -1,    -1,    66,    53,    54,    55,    56,
      57,    58,    -1,    60,    -1,    62,    -1,    64,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    62,    -1,    64,    53,    54,    55,    56,    57,
      58,    -1,    60,    -1,    62,    -1,    64,    53,    54,    55,
      56,    57,    58,    -1,    60,    -1,    62,    -1,    64,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    53,    54,    55,    56,    57,    58,
      -1,    60,    61,    62,    53,    54,    55,    56,    57,    58,
      -1,    60,    -1,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    71,     0,     1,     3,     4,     5,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    24,    25,
      26,    27,    50,    51,    54,    55,    59,    63,    66,    67,
      72,    75,    76,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    92,    93,    65,    66,
      63,    63,    24,    66,    86,    24,     7,    24,    75,    63,
      86,    86,    86,    86,    86,    86,    65,    78,    81,    17,
      24,    53,    63,    77,    65,    81,    18,    19,    20,    21,
      22,    23,    53,    54,    55,    56,    57,    58,    60,    62,
      66,    86,    86,    66,    67,    63,    63,    60,    86,    91,
      64,    24,    86,    24,    78,    64,    68,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      24,    64,    64,    73,    86,    64,    86,    64,    68,    66,
      79,    78,    61,    81,    81,    65,    74,    75,    64,    61,
      86,     9,    66,    17,    24,    81,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    71,    71,    71,    72,
      73,    73,    74,    74,    75,    75,    75,    75,    75,    75,
      76,    77,    77,    77,    78,    78,    79,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    82,    83,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      90,    91,    91,    91,    92,    92,    92,    93,    93,    93,
      93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     5,
       3,     0,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     2,     1,     2,     3,     2,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     2,     4,     5,     5,
       7,     2,     3,     1,     1,     1,     1,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     4,     5,     5,
       4,     3,     1,     0,     1,     4,     3,     1,     1,     1,
       1,     1,     1
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
#line 40 "parser.y" /* yacc.c:1646  */
    {yyparse_astree = (yyvsp[0]); }
#line 1458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 42 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1 ((yyvsp[-1]), (yyvsp[0])); }
#line 1464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 43 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1 ((yyvsp[-1]), (yyvsp[0])); }
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 44 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1 ((yyvsp[-1]), (yyvsp[0])); }
#line 1476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 1482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 46 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 1488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_parseroot (); }
#line 1494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 50 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[-3]),TOK_TYPEID); (yyval) = adopt2((yyvsp[-4]),(yyvsp[-3]),(yyvsp[-1]));free_ast2((yyvsp[-2]),(yyvsp[0])); }
#line 1500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 52 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1((yyvsp[-2]),(yyvsp[-1]));free_ast((yyvsp[0])); }
#line 1506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 53 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_parsenode(TOK_FIELDS,"fields"); }
#line 1512 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 55 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[0]),TOK_FIELD); (yyval) = adopt2((yyvsp[-2]),(yyvsp[0]),(yyvsp[-1])); }
#line 1518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 56 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[0]),TOK_FIELD); (yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 58 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 60 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 62 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 63 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]);}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 65 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt3(new_parsenode(TOK_FUNCTION,"function"),(yyvsp[-3]),(yyvsp[-2]),(yyvsp[0]));free_ast((yyvsp[-1]));}
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 67 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1((yyvsp[-2]),(yyvsp[0])); free_ast((yyvsp[-1])); }
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 68 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[-1]),TOK_PARAM); (yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 69 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[0]),TOK_PARAM); (yyval) = (yyvsp[0]);}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 71 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[0]),TOK_DECLID); (yyval) = adopt1((yyvsp[-1]),(yyvsp[0]));}
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 72 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[-1]),TOK_DECLID); (yyval) = adopt2((yyvsp[-2]),(yyvsp[0]),(yyvsp[-1]));}
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 75 "parser.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[-1]); free_ast((yyvsp[0]));  }
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 76 "parser.y" /* yacc.c:1646  */
    {swap((yyvsp[-1]),TOK_BLOCK); (yyval) = (yyvsp[-1]); free_ast((yyvsp[0]));}
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_parsenode(TOK_BLOCK,"block"); free_ast((yyvsp[0]));}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 79 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 80 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[-1]),TOK_BLOCK); (yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 82 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 83 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 84 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 86 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 87 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 89 "parser.y" /* yacc.c:1646  */
    {swap((yyvsp[-2]),TOK_VARDECL); (yyval) = adopt2((yyvsp[-2]),(yyvsp[-3]),(yyvsp[-1])); free_ast((yyvsp[0]));}
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval) = adopt2((yyvsp[-4]),(yyvsp[-2]),(yyvsp[0])); free_ast2((yyvsp[-3]),(yyvsp[-1]));}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval) = adopt2(new_parsenode(TOK_IFELSE,"ifelse"),(yyvsp[-2]),(yyvsp[0])); free_ast((yyvsp[-4]));free_ast2((yyvsp[-3]),(yyvsp[-1]));}
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt3(new_parsenode(TOK_IFELSE,"ifelse"),(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0])); free_ast2((yyvsp[-6]),(yyvsp[-1]));free_ast2((yyvsp[-5]),(yyvsp[-3]));}
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 96 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[-1]), TOK_RETURNVOID); (yyval)=(yyvsp[-1]); free_ast((yyvsp[0]));}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1((yyvsp[-2]),(yyvsp[-1])); free_ast((yyvsp[0])); }
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 101 "parser.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 103 "parser.y" /* yacc.c:1646  */
    { free_ast2((yyvsp[-2]),(yyvsp[0])); (yyval)=(yyvsp[-1]); }
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 104 "parser.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1734 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 105 "parser.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]); }
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 108 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1758 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1764 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1770 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1800 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 118 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0])); }
#line 1812 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 120 "parser.y" /* yacc.c:1646  */
    {swap((yyvsp[-1]),TOK_POS); (yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 121 "parser.y" /* yacc.c:1646  */
    {swap((yyvsp[-1]),TOK_NEG); (yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1830 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1((yyvsp[-1]),(yyvsp[0])); }
#line 1842 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 126 "parser.y" /* yacc.c:1646  */
    {swap((yyvsp[-2]),TOK_TYPEID); (yyval) = adopt1((yyvsp[-3]),(yyvsp[-2])); free_ast2((yyvsp[-1]),(yyvsp[0]));}
#line 1848 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 127 "parser.y" /* yacc.c:1646  */
    {swap((yyvsp[-3]),TOK_NEWSTRING); (yyval) = adopt2((yyvsp[-4]),(yyvsp[-3]),(yyvsp[-1])); free_ast2((yyvsp[-2]),(yyvsp[-1]));}
#line 1854 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 128 "parser.y" /* yacc.c:1646  */
    {swap((yyvsp[-3]),TOK_NEWARRAY); (yyval) = adopt2((yyvsp[-4]),(yyvsp[-3]),(yyvsp[-1])); free_ast2((yyvsp[-2]),(yyvsp[0]));}
#line 1860 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 130 "parser.y" /* yacc.c:1646  */
    {swap((yyvsp[-2]),TOK_CALL); (yyval) = adopt2((yyvsp[-2]),(yyvsp[-3]),(yyvsp[-1])); free_ast((yyvsp[0]));}
#line 1866 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval) = adopt1((yyvsp[-2]),(yyvsp[0])); free_ast((yyvsp[-1])); }
#line 1872 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 133 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1878 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_parsenode(TOK_EXPRLIST,"exprlist"); }
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1890 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 137 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[-2]),TOK_INDEX); (yyval) = adopt2((yyvsp[-2]),(yyvsp[-3]),(yyvsp[-1])); free_ast((yyvsp[0])); }
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 138 "parser.y" /* yacc.c:1646  */
    { swap((yyvsp[0]),TOK_FIELD); (yyval) = adopt2((yyvsp[-1]),(yyvsp[-2]),(yyvsp[0]));}
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1926 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 144 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1938 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1942 "parser.tab.c" /* yacc.c:1646  */
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
#line 147 "parser.y" /* yacc.c:1906  */


const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}

