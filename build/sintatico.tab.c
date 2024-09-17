/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "source/sintatico.y"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../source/symbol_table.h"
#include "../source/code_generator.h"

int yylex(void);
void yyerror(const char* s);

bool in_print_call;
bool in_local_definition;

extern char* function_definition_name;

int semantic_erros;

int current_line_number;

unsigned int current_scope_level;

extern FILE* yyin;
extern FILE* yyout;

// Variaveis pendentes são variáveis que estão esperando uma atribuição
typedef struct pending_variable {
    char* name;
    struct pending_variable* next;
} pending_variable;

pending_variable* first_pending_var = NULL;

void add_pending_variable(char* name) {
    pending_variable* new_pending_var = (pending_variable*) malloc(sizeof(pending_variable));
    new_pending_var->name = name;

    if (first_pending_var == NULL) {
        first_pending_var = new_pending_var;
    } else {
        pending_variable* current_var = first_pending_var;

        while (current_var->next) {
            current_var = current_var->next;
        }

        current_var->next = new_pending_var;
    }
}

// Gera uma atribuição para a primeira variável pendente
void gen_assignment_for_pending_var() {
    gen_assignment(search_symbol(first_pending_var->name, current_scope_level, false));
    
    pending_variable* next_var = first_pending_var->next;
    free(first_pending_var);
    first_pending_var = next_var;
}

void enter_scope() {
    current_scope_level++;
}

void exit_scope() {
    delete_symbols_in_scope(current_scope_level);
    current_scope_level--;
}


#line 140 "build/sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ATRIBUICAO = 3,                 /* ATRIBUICAO  */
  YYSYMBOL_VIRGULA = 4,                    /* VIRGULA  */
  YYSYMBOL_PONTO_VIRGULA = 5,              /* PONTO_VIRGULA  */
  YYSYMBOL_PARENTESE_ESQUERDO = 6,         /* PARENTESE_ESQUERDO  */
  YYSYMBOL_PARENTESE_DIREITO = 7,          /* PARENTESE_DIREITO  */
  YYSYMBOL_NIL = 8,                        /* NIL  */
  YYSYMBOL_FALSO = 9,                      /* FALSO  */
  YYSYMBOL_VERDADEIRO = 10,                /* VERDADEIRO  */
  YYSYMBOL_LOCAL = 11,                     /* LOCAL  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_THEN = 13,                      /* THEN  */
  YYSYMBOL_ELSE = 14,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 15,                    /* ELSEIF  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_END = 17,                       /* END  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_REPEAT = 19,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 20,                     /* UNTIL  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_FUNCTION = 22,                  /* FUNCTION  */
  YYSYMBOL_NUMERO = 23,                    /* NUMERO  */
  YYSYMBOL_STRING = 24,                    /* STRING  */
  YYSYMBOL_IDENTIFICADOR = 25,             /* IDENTIFICADOR  */
  YYSYMBOL_MENOR_QUE = 26,                 /* MENOR_QUE  */
  YYSYMBOL_MAIOR_QUE = 27,                 /* MAIOR_QUE  */
  YYSYMBOL_IGUALDADE = 28,                 /* IGUALDADE  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_MAIS = 31,                      /* MAIS  */
  YYSYMBOL_MENOS = 32,                     /* MENOS  */
  YYSYMBOL_MULTIPLICACAO = 33,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 34,                   /* DIVISAO  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_programa = 37,                  /* programa  */
  YYSYMBOL_lista_comandos_e_definicoes = 38, /* lista_comandos_e_definicoes  */
  YYSYMBOL_lista_comandos = 39,            /* lista_comandos  */
  YYSYMBOL_comando = 40,                   /* comando  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_42_2 = 42,                      /* $@2  */
  YYSYMBOL_43_3 = 43,                      /* $@3  */
  YYSYMBOL_44_4 = 44,                      /* $@4  */
  YYSYMBOL_45_5 = 45,                      /* $@5  */
  YYSYMBOL_46_6 = 46,                      /* $@6  */
  YYSYMBOL_47_7 = 47,                      /* $@7  */
  YYSYMBOL_48_8 = 48,                      /* $@8  */
  YYSYMBOL_variavel = 49,                  /* variavel  */
  YYSYMBOL_definicao_variavel = 50,        /* definicao_variavel  */
  YYSYMBOL_lista_atribuicao = 51,          /* lista_atribuicao  */
  YYSYMBOL_lista_variaveis = 52,           /* lista_variaveis  */
  YYSYMBOL_bloco_escopo = 53,              /* bloco_escopo  */
  YYSYMBOL_54_9 = 54,                      /* $@9  */
  YYSYMBOL_comando_condicional = 55,       /* comando_condicional  */
  YYSYMBOL_56_10 = 56,                     /* $@10  */
  YYSYMBOL_57_11 = 57,                     /* $@11  */
  YYSYMBOL_comando_if = 58,                /* comando_if  */
  YYSYMBOL_59_12 = 59,                     /* $@12  */
  YYSYMBOL_comando_elseif = 60,            /* comando_elseif  */
  YYSYMBOL_61_13 = 61,                     /* $@13  */
  YYSYMBOL_62_14 = 62,                     /* $@14  */
  YYSYMBOL_lista_elseif = 63,              /* lista_elseif  */
  YYSYMBOL_lista_expressoes = 64,          /* lista_expressoes  */
  YYSYMBOL_definicao_funcao = 65,          /* definicao_funcao  */
  YYSYMBOL_66_15 = 66,                     /* $@15  */
  YYSYMBOL_expressao = 67,                 /* expressao  */
  YYSYMBOL_chamada_funcao = 68,            /* chamada_funcao  */
  YYSYMBOL_69_16 = 69,                     /* $@16  */
  YYSYMBOL_argumentos = 70                 /* argumentos  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   276

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   116,   117,   118,   119,   120,   121,   122,
     123,   127,   128,   129,   130,   134,   135,   135,   136,   137,
     137,   137,   138,   138,   138,   139,   140,   141,   145,   140,
     150,   171,   179,   180,   183,   184,   188,   189,   192,   192,
     195,   196,   196,   197,   198,   198,   201,   201,   205,   205,
     205,   209,   210,   214,   215,   220,   219,   236,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   274,   273,   292,   293
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ATRIBUICAO",
  "VIRGULA", "PONTO_VIRGULA", "PARENTESE_ESQUERDO", "PARENTESE_DIREITO",
  "NIL", "FALSO", "VERDADEIRO", "LOCAL", "IF", "THEN", "ELSE", "ELSEIF",
  "DO", "END", "WHILE", "REPEAT", "UNTIL", "FOR", "FUNCTION", "NUMERO",
  "STRING", "IDENTIFICADOR", "MENOR_QUE", "MAIOR_QUE", "IGUALDADE", "AND",
  "OR", "MAIS", "MENOS", "MULTIPLICACAO", "DIVISAO", "NOT", "$accept",
  "programa", "lista_comandos_e_definicoes", "lista_comandos", "comando",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "variavel",
  "definicao_variavel", "lista_atribuicao", "lista_variaveis",
  "bloco_escopo", "$@9", "comando_condicional", "$@10", "$@11",
  "comando_if", "$@12", "comando_elseif", "$@13", "$@14", "lista_elseif",
  "lista_expressoes", "definicao_funcao", "$@15", "expressao",
  "chamada_funcao", "$@16", "argumentos", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     229,   -97,   154,   -97,   -97,   -97,   -97,   -22,     8,    22,
     -97,   194,    16,   -97,   -97,     7,    13,   206,   -97,    10,
     154,   -97,   -97,   -97,   -97,   -97,     8,   154,   154,   242,
     -97,   241,   154,   241,    10,    35,    46,   -97,   229,   -97,
     154,    10,   -97,   -97,   -97,    39,    50,   229,   -97,   -97,
      42,   -97,   -97,   -97,   164,    14,   -97,   154,   154,   154,
     154,   154,   154,   154,   154,   154,    54,    52,   218,   242,
     -97,    69,    66,    83,   -97,   -97,   242,    71,   241,   154,
     -97,   -97,   -97,    10,   -97,   -21,   -21,   -21,     0,     0,
      14,    14,   -97,   -97,   241,   -97,   241,   -97,    60,    58,
     154,   -97,   -97,    74,   106,   154,   -97,   242,   241,   -97,
     -97,   -97,   -97,   154,   115,   241,   -97,   154,   242,    70,
     -97,   242,   -97,    65,   -97,   241,   154,   -97,   -97,   125,
     154,   242,    60,   -97
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    16,     0,    38,    19,    22,    26,     0,    31,     0,
       2,     3,     0,    15,    18,     0,    40,     7,    30,     0,
       0,    62,    60,    61,    59,    58,    57,     0,     0,    46,
      74,     0,     0,     0,     0,     0,     0,     1,     4,     5,
       0,     0,    25,    41,    48,    52,    43,     8,     9,    31,
      36,    17,    32,    33,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    20,
      23,     0,     0,     0,    77,     6,    34,     0,     0,     0,
      51,    44,    10,     0,    75,    69,    70,    71,    67,    68,
      65,    66,    63,    64,     0,    39,    12,    13,     0,     0,
       0,    55,    78,     0,    53,     0,    42,    49,     0,    37,
      47,    14,    21,     0,     0,     0,    79,     0,    35,     0,
      45,    24,    27,     0,    54,     0,     0,    56,    50,     0,
       0,    28,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,   -97,    32,   -28,     4,   -97,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -18,   -97,   -12,     2,   -96,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,    41,   -29,   -97,
     -97,    -2,     6,   -97,   -97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    67,    68,    19,    32,    98,    33,    99,
      34,   126,   132,    12,    51,    13,    53,    14,    31,    15,
      78,   108,    16,    66,    45,    79,   119,    46,   103,    17,
     115,   104,    30,    36,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    50,   112,    35,    11,    70,    18,    52,    60,    61,
      62,    63,    64,    65,   -76,    11,    71,    18,    54,    40,
      41,    11,    37,    18,    42,    55,    56,    43,    44,    77,
      69,    62,    63,    64,    65,    49,   133,    18,    76,    18,
      97,    72,    11,    39,    18,    40,    83,    64,    65,    48,
     106,    11,    73,    18,    44,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    81,    50,   110,    94,   111,    95,
      75,    77,   100,   101,    18,   105,     3,   107,   113,    82,
     120,   116,   127,   125,    18,   109,    80,   123,   124,    20,
     102,    21,    22,    23,     0,     0,     0,   128,   114,     0,
      18,     0,    18,   118,     0,     0,    24,    25,    26,     0,
     117,   121,     0,     0,    18,    27,     0,     0,    28,   122,
       0,    18,     0,     0,   129,     0,     0,     0,   131,   130,
       0,    18,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    57,    58,    59,    60,    61,    62,    63,    64,    65,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      20,     0,    21,    22,    23,     0,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,    24,    25,    26,
       0,     0,     0,     0,     0,     0,    27,     0,     0,    28,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    38,
       0,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       3,    47,     4,     5,     0,     6,     7,     1,     2,     8,
       0,     0,     3,    96,     4,     5,     0,     6,     7,     1,
       2,     8,     0,     0,     3,     0,     4,     5,     0,     6,
       1,     2,     0,     8,     0,     3,     0,     4,     5,     0,
       6,     7,     1,     2,     8,     0,     0,     3,     0,     4,
       5,     0,     6,     0,     0,     0,     8,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
       2,    19,    98,    25,     0,    33,     0,    19,    29,    30,
      31,    32,    33,    34,     6,    11,    34,    11,    20,     3,
       4,    17,     0,    17,    17,    27,    28,    14,    15,    41,
      32,    31,    32,    33,    34,    25,   132,    31,    40,    33,
      68,     6,    38,    11,    38,     3,     4,    33,    34,    17,
      78,    47,     6,    47,    15,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    14,    83,    94,    13,    96,    17,
      38,    83,     3,     7,    68,     4,    16,    79,    20,    47,
     108,     7,    17,    13,    78,    83,    45,   115,   117,     6,
       7,     8,     9,    10,    -1,    -1,    -1,   125,   100,    -1,
      94,    -1,    96,   105,    -1,    -1,    23,    24,    25,    -1,
       4,   113,    -1,    -1,   108,    32,    -1,    -1,    35,     4,
      -1,   115,    -1,    -1,   126,    -1,    -1,    -1,   130,     4,
      -1,   125,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       6,    -1,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,     7,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,
      26,    27,    28,    29,    30,    31,    32,    33,    34,     5,
      -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,     5,    18,    19,    -1,    21,    22,    11,    12,    25,
      -1,    -1,    16,     5,    18,    19,    -1,    21,    22,    11,
      12,    25,    -1,    -1,    16,    -1,    18,    19,    -1,    21,
      11,    12,    -1,    25,    -1,    16,    -1,    18,    19,    -1,
      21,    22,    11,    12,    25,    -1,    -1,    16,    -1,    18,
      19,    -1,    21,    -1,    -1,    -1,    25,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    16,    18,    19,    21,    22,    25,    37,
      38,    40,    49,    51,    53,    55,    58,    65,    68,    41,
       6,     8,     9,    10,    23,    24,    25,    32,    35,    67,
      68,    54,    42,    44,    46,    25,    69,     0,     5,    38,
       3,     4,    17,    14,    15,    60,    63,     5,    38,    25,
      49,    50,    51,    52,    67,    67,    67,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    59,    39,    40,    67,
      39,    49,     6,     6,    70,    38,    67,    51,    56,    61,
      63,    14,    38,     4,     7,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    13,    17,     5,    39,    43,    45,
       3,     7,     7,    64,    67,     4,    39,    67,    57,    52,
      39,    39,    53,    20,    67,    66,     7,     4,    67,    62,
      39,    67,     4,    39,    64,    13,    47,    17,    39,    67,
       4,    67,    48,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    38,    38,    38,    38,
      38,    39,    39,    39,    39,    40,    41,    40,    40,    42,
      43,    40,    44,    45,    40,    40,    46,    47,    48,    40,
      40,    49,    50,    50,    51,    51,    52,    52,    54,    53,
      55,    56,    55,    55,    57,    55,    59,    58,    61,    62,
      60,    63,    63,    64,    64,    66,    65,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    69,    68,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     1,     2,     2,
       3,     1,     2,     2,     3,     1,     0,     3,     1,     0,
       0,     5,     0,     0,     6,     2,     0,     0,     0,    12,
       1,     1,     1,     1,     3,     5,     1,     3,     0,     4,
       1,     0,     4,     2,     0,     5,     0,     5,     0,     0,
       6,     2,     1,     1,     3,     0,     7,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     3,     0,     3,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: lista_comandos_e_definicoes  */
#line 103 "source/sintatico.y"
    { 
        printf("\nPrograma sintaticamente CORRETO!\n"); 

        if (semantic_erros != 0) {
            printf("\nPrograma semanticamente INCORRETO! (%d erros)\n\n", semantic_erros); 
        } else {
            printf("\nPrograma semanticamente CORRETO!\n\n"); 
            gen_object_code(yyout); 
        }
    }
#line 1714 "build/sintatico.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 135 "source/sintatico.y"
            { in_local_definition = true; }
#line 1720 "build/sintatico.tab.c"
    break;

  case 17: /* comando: LOCAL $@1 definicao_variavel  */
#line 135 "source/sintatico.y"
                                                               { in_local_definition = false; }
#line 1726 "build/sintatico.tab.c"
    break;

  case 19: /* $@2: %empty  */
#line 137 "source/sintatico.y"
            { save_code_position(); }
#line 1732 "build/sintatico.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 137 "source/sintatico.y"
                                                { save_code_position(); skip_code_position(2); }
#line 1738 "build/sintatico.tab.c"
    break;

  case 21: /* comando: WHILE $@2 expressao $@3 bloco_escopo  */
#line 137 "source/sintatico.y"
                                                                                                              { gen_while(); }
#line 1744 "build/sintatico.tab.c"
    break;

  case 22: /* $@4: %empty  */
#line 138 "source/sintatico.y"
             { save_code_position(); enter_scope(); }
#line 1750 "build/sintatico.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 138 "source/sintatico.y"
                                                                     { exit_scope(); }
#line 1756 "build/sintatico.tab.c"
    break;

  case 24: /* comando: REPEAT $@4 lista_comandos $@5 UNTIL expressao  */
#line 138 "source/sintatico.y"
                                                                                                       { gen_repeat(); }
#line 1762 "build/sintatico.tab.c"
    break;

  case 25: /* comando: comando_condicional END  */
#line 139 "source/sintatico.y"
                              { gen_if_end_jump((yyvsp[-1].ival)); }
#line 1768 "build/sintatico.tab.c"
    break;

  case 26: /* $@6: %empty  */
#line 140 "source/sintatico.y"
          { in_local_definition = true; enter_scope(); }
#line 1774 "build/sintatico.tab.c"
    break;

  case 27: /* $@7: %empty  */
#line 141 "source/sintatico.y"
    { 
        gen_assignment_for_pending_var(); 
        in_local_definition = false; 
    }
#line 1783 "build/sintatico.tab.c"
    break;

  case 28: /* $@8: %empty  */
#line 145 "source/sintatico.y"
                                { save_code_position(); }
#line 1789 "build/sintatico.tab.c"
    break;

  case 29: /* comando: FOR $@6 variavel ATRIBUICAO expressao VIRGULA $@7 expressao VIRGULA expressao $@8 bloco_escopo  */
#line 146 "source/sintatico.y"
    { 
        gen_for(search_symbol((yyvsp[-9].sval), current_scope_level, false)); 
        exit_scope(); 
    }
#line 1798 "build/sintatico.tab.c"
    break;

  case 30: /* comando: chamada_funcao  */
#line 151 "source/sintatico.y"
    { 
        if (strcmp((yyvsp[0].sval), "print") != 0 && (strcmp((yyvsp[0].sval), "read") != 0)) {
            symbol* function = search_symbol((yyvsp[0].sval), current_scope_level, true);

            if (function == NULL) {
                printf(
                    "\n*** ERRO SEMÂNTICO | Linha %d: Função '%s' não foi declarada!\n", 
                    current_line_number, (yyvsp[0].sval)
                );
                semantic_erros++;
            } else {
                function->is_used = true;

                gen_function_code(strdup((yyvsp[0].sval)));
            }
        }
    }
#line 1820 "build/sintatico.tab.c"
    break;

  case 31: /* variavel: IDENTIFICADOR  */
#line 172 "source/sintatico.y"
    { 
        insert_symbol((yyvsp[0].sval), in_local_definition ? current_scope_level : 0, current_line_number, false); 
        add_pending_variable((yyvsp[0].sval));
        (yyval.sval) = (yyvsp[0].sval);
    }
#line 1830 "build/sintatico.tab.c"
    break;

  case 34: /* lista_atribuicao: variavel ATRIBUICAO expressao  */
#line 183 "source/sintatico.y"
                                                            { gen_assignment_for_pending_var(); }
#line 1836 "build/sintatico.tab.c"
    break;

  case 35: /* lista_atribuicao: variavel VIRGULA lista_atribuicao VIRGULA expressao  */
#line 184 "source/sintatico.y"
                                                            { gen_assignment_for_pending_var(); }
#line 1842 "build/sintatico.tab.c"
    break;

  case 36: /* lista_variaveis: variavel  */
#line 188 "source/sintatico.y"
                                            { gen_num(0); gen_assignment_for_pending_var(); /* A variavel recebe 0 */ }
#line 1848 "build/sintatico.tab.c"
    break;

  case 37: /* lista_variaveis: variavel VIRGULA lista_variaveis  */
#line 189 "source/sintatico.y"
                                            { gen_num(0); gen_assignment_for_pending_var(); /* A variavel recebe 0 */ }
#line 1854 "build/sintatico.tab.c"
    break;

  case 38: /* $@9: %empty  */
#line 192 "source/sintatico.y"
       { enter_scope(); }
#line 1860 "build/sintatico.tab.c"
    break;

  case 39: /* bloco_escopo: DO $@9 lista_comandos END  */
#line 192 "source/sintatico.y"
                                             { exit_scope(); }
#line 1866 "build/sintatico.tab.c"
    break;

  case 40: /* comando_condicional: comando_if  */
#line 195 "source/sintatico.y"
                                                                          { (yyval.ival) = 1; gen_if_exp_jump(); }
#line 1872 "build/sintatico.tab.c"
    break;

  case 41: /* $@10: %empty  */
#line 196 "source/sintatico.y"
                      { gen_if_exp_jump(); }
#line 1878 "build/sintatico.tab.c"
    break;

  case 42: /* comando_condicional: comando_if ELSE $@10 lista_comandos  */
#line 196 "source/sintatico.y"
                                                                          { (yyval.ival) = 1; }
#line 1884 "build/sintatico.tab.c"
    break;

  case 43: /* comando_condicional: comando_if lista_elseif  */
#line 197 "source/sintatico.y"
                                                                          { (yyval.ival) = 1 + (yyvsp[0].ival); gen_if_exp_jump(); }
#line 1890 "build/sintatico.tab.c"
    break;

  case 44: /* $@11: %empty  */
#line 198 "source/sintatico.y"
                                   { gen_if_exp_jump(); }
#line 1896 "build/sintatico.tab.c"
    break;

  case 45: /* comando_condicional: comando_if lista_elseif ELSE $@11 lista_comandos  */
#line 198 "source/sintatico.y"
                                                                          { (yyval.ival) = 1 + (yyvsp[-3].ival); }
#line 1902 "build/sintatico.tab.c"
    break;

  case 46: /* $@12: %empty  */
#line 201 "source/sintatico.y"
                 {  save_code_position(); skip_code_position(2); enter_scope(); }
#line 1908 "build/sintatico.tab.c"
    break;

  case 47: /* comando_if: IF expressao $@12 THEN lista_comandos  */
#line 202 "source/sintatico.y"
                            { exit_scope(); save_code_position(); skip_code_position(1); }
#line 1914 "build/sintatico.tab.c"
    break;

  case 48: /* $@13: %empty  */
#line 205 "source/sintatico.y"
           { gen_if_exp_jump(); }
#line 1920 "build/sintatico.tab.c"
    break;

  case 49: /* $@14: %empty  */
#line 205 "source/sintatico.y"
                                            { save_code_position(); skip_code_position(2); enter_scope(); }
#line 1926 "build/sintatico.tab.c"
    break;

  case 50: /* comando_elseif: ELSEIF $@13 expressao $@14 THEN lista_comandos  */
#line 206 "source/sintatico.y"
                            { exit_scope(); save_code_position(); skip_code_position(1); }
#line 1932 "build/sintatico.tab.c"
    break;

  case 51: /* lista_elseif: comando_elseif lista_elseif  */
#line 209 "source/sintatico.y"
                                      { (yyval.ival) = 1 + (yyvsp[0].ival); }
#line 1938 "build/sintatico.tab.c"
    break;

  case 52: /* lista_elseif: comando_elseif  */
#line 210 "source/sintatico.y"
                                      { (yyval.ival) = 1; }
#line 1944 "build/sintatico.tab.c"
    break;

  case 53: /* lista_expressoes: expressao  */
#line 214 "source/sintatico.y"
                                                { if (in_print_call) gen_print(); }
#line 1950 "build/sintatico.tab.c"
    break;

  case 54: /* lista_expressoes: expressao VIRGULA lista_expressoes  */
#line 215 "source/sintatico.y"
                                                { if (in_print_call) gen_print(); }
#line 1956 "build/sintatico.tab.c"
    break;

  case 55: /* $@15: %empty  */
#line 220 "source/sintatico.y"
    {  
        insert_symbol((yyvsp[-2].sval), in_local_definition ? current_scope_level : 0, current_line_number, true); 
        save_code_position();
        
        enter_scope();
        clear_function_code(strdup((yyvsp[-2].sval)));
        function_definition_name = strdup((yyvsp[-2].sval));
    }
#line 1969 "build/sintatico.tab.c"
    break;

  case 56: /* definicao_funcao: FUNCTION IDENTIFICADOR PARENTESE_ESQUERDO PARENTESE_DIREITO $@15 lista_comandos END  */
#line 228 "source/sintatico.y"
    {
        exit_scope();
        function_definition_name = NULL;
        revert_code_position();
    }
#line 1979 "build/sintatico.tab.c"
    break;

  case 57: /* expressao: IDENTIFICADOR  */
#line 237 "source/sintatico.y"
    { 
        symbol* var = search_symbol((yyvsp[0].sval), current_scope_level, false);

        if (var == NULL) {
            printf(
                "\n*** ERRO SEMÂNTICO | Linha %d: Variável '%s' não foi declarada!\n", 
                current_line_number, (yyvsp[0].sval)
            );
            semantic_erros++;
        } else {
            var->is_used = true;

            gen_variable_value(var);
        }
    }
#line 1999 "build/sintatico.tab.c"
    break;

  case 58: /* expressao: STRING  */
#line 252 "source/sintatico.y"
                                                { /* Aqui você pode gerar o código para uma string */ }
#line 2005 "build/sintatico.tab.c"
    break;

  case 59: /* expressao: NUMERO  */
#line 253 "source/sintatico.y"
                                                { gen_num((yyvsp[0].ival)); }
#line 2011 "build/sintatico.tab.c"
    break;

  case 60: /* expressao: FALSO  */
#line 254 "source/sintatico.y"
                                                { gen_num(0); }
#line 2017 "build/sintatico.tab.c"
    break;

  case 61: /* expressao: VERDADEIRO  */
#line 255 "source/sintatico.y"
                                                { gen_num(1); }
#line 2023 "build/sintatico.tab.c"
    break;

  case 62: /* expressao: NIL  */
#line 256 "source/sintatico.y"
                                                { gen_num(0); }
#line 2029 "build/sintatico.tab.c"
    break;

  case 63: /* expressao: expressao MULTIPLICACAO expressao  */
#line 257 "source/sintatico.y"
                                                { gen_binary_operation(OP_MUL); }
#line 2035 "build/sintatico.tab.c"
    break;

  case 64: /* expressao: expressao DIVISAO expressao  */
#line 258 "source/sintatico.y"
                                                { gen_binary_operation(OP_DIV); }
#line 2041 "build/sintatico.tab.c"
    break;

  case 65: /* expressao: expressao MAIS expressao  */
#line 259 "source/sintatico.y"
                                                { gen_binary_operation(OP_ADD); }
#line 2047 "build/sintatico.tab.c"
    break;

  case 66: /* expressao: expressao MENOS expressao  */
#line 260 "source/sintatico.y"
                                                { gen_binary_operation(OP_SUB); }
#line 2053 "build/sintatico.tab.c"
    break;

  case 67: /* expressao: expressao AND expressao  */
#line 261 "source/sintatico.y"
                                                { gen_binary_operation(OP_AND); }
#line 2059 "build/sintatico.tab.c"
    break;

  case 68: /* expressao: expressao OR expressao  */
#line 262 "source/sintatico.y"
                                                { gen_binary_operation(OP_OR); }
#line 2065 "build/sintatico.tab.c"
    break;

  case 69: /* expressao: expressao MENOR_QUE expressao  */
#line 263 "source/sintatico.y"
                                                { gen_binary_operation(OP_LESS_THAN); }
#line 2071 "build/sintatico.tab.c"
    break;

  case 70: /* expressao: expressao MAIOR_QUE expressao  */
#line 264 "source/sintatico.y"
                                                { gen_binary_operation(OP_GREATER_THAN); }
#line 2077 "build/sintatico.tab.c"
    break;

  case 71: /* expressao: expressao IGUALDADE expressao  */
#line 265 "source/sintatico.y"
                                                { gen_binary_operation(OP_EQUALITY); }
#line 2083 "build/sintatico.tab.c"
    break;

  case 72: /* expressao: MENOS expressao  */
#line 266 "source/sintatico.y"
                                                { gen_unary_operation(OP_NEG); }
#line 2089 "build/sintatico.tab.c"
    break;

  case 73: /* expressao: NOT expressao  */
#line 267 "source/sintatico.y"
                                                { gen_unary_operation(OP_NOT); }
#line 2095 "build/sintatico.tab.c"
    break;

  case 74: /* expressao: chamada_funcao  */
#line 268 "source/sintatico.y"
                                                { if (strcmp((yyvsp[0].sval), "read") != 0) gen_num(0); }
#line 2101 "build/sintatico.tab.c"
    break;

  case 76: /* $@16: %empty  */
#line 274 "source/sintatico.y"
    {
        if (strcmp((yyvsp[0].sval), "print") == 0) {
            in_print_call = true; 
        } else if (strcmp((yyvsp[0].sval), "read") == 0) {
            gen_read();
        }
    }
#line 2113 "build/sintatico.tab.c"
    break;

  case 77: /* chamada_funcao: IDENTIFICADOR $@16 argumentos  */
#line 282 "source/sintatico.y"
    {
        if (strcmp((yyvsp[-2].sval), "print") == 0) {
            in_print_call = false; 
        }

        (yyval.sval) = strdup((yyvsp[-2].sval));
    }
#line 2125 "build/sintatico.tab.c"
    break;


#line 2129 "build/sintatico.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 295 "source/sintatico.y"


int main(int argc, char* argv[]) {
    if (argc > 1) {
        yyin = (FILE *) fopen(argv[1], "r");

        if (yyin == NULL) {
            printf("\nArquivo de entrada inválido!\n\n");
            return 0;
        }
    } else {
        printf("\nPara usar o compilador execute: \"./compilador ./<seu_programa>.lua ./<seu_arquivo_objeto>.tm\"\n\n");
        return 0;
    }

    if (argc > 2) {
	    yyout = (FILE *) fopen(argv[2], "w");
    } else {
        yyout = stdout;
    }

    yyparse();

    verify_not_used_symbols();

    fclose(yyin);
    fclose(yyout);
}
