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
    gen_assignment(search_variable(first_pending_var->name, current_scope_level));
    
    pending_variable* next_var = first_pending_var->next;
    free(first_pending_var);
    first_pending_var = next_var;
}

void enter_scope() {
    current_scope_level++;
}

void exit_scope() {
    delete_variables_in_scope(current_scope_level);
    current_scope_level--;
}


#line 138 "build/sintatico.tab.c"

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
  YYSYMBOL_RETICENCIAS = 8,                /* RETICENCIAS  */
  YYSYMBOL_NIL = 9,                        /* NIL  */
  YYSYMBOL_FALSO = 10,                     /* FALSO  */
  YYSYMBOL_VERDADEIRO = 11,                /* VERDADEIRO  */
  YYSYMBOL_LOCAL = 12,                     /* LOCAL  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_THEN = 14,                      /* THEN  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 16,                    /* ELSEIF  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_END = 18,                       /* END  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_REPEAT = 20,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 21,                     /* UNTIL  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_FUNCTION = 23,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_NUMERO = 25,                    /* NUMERO  */
  YYSYMBOL_IDENTIFICADOR = 26,             /* IDENTIFICADOR  */
  YYSYMBOL_MENOR_QUE = 27,                 /* MENOR_QUE  */
  YYSYMBOL_MAIOR_QUE = 28,                 /* MAIOR_QUE  */
  YYSYMBOL_IGUALDADE = 29,                 /* IGUALDADE  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_MAIS = 32,                      /* MAIS  */
  YYSYMBOL_MENOS = 33,                     /* MENOS  */
  YYSYMBOL_MULTIPLICACAO = 34,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 35,                   /* DIVISAO  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
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
  YYSYMBOL_lista_parametros = 64,          /* lista_parametros  */
  YYSYMBOL_lista_expressoes = 65,          /* lista_expressoes  */
  YYSYMBOL_expressao = 66,                 /* expressao  */
  YYSYMBOL_chamada_funcao = 67,            /* chamada_funcao  */
  YYSYMBOL_68_15 = 68,                     /* $@15  */
  YYSYMBOL_argumentos = 69,                /* argumentos  */
  YYSYMBOL_corpo_funcao = 70,              /* corpo_funcao  */
  YYSYMBOL_retorno = 71                    /* retorno  */
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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    99,    99,   113,   114,   115,   116,   117,   118,   119,
     123,   124,   124,   125,   126,   126,   126,   127,   127,   127,
     128,   129,   130,   131,   135,   130,   140,   141,   145,   153,
     154,   157,   158,   162,   163,   166,   166,   169,   170,   170,
     171,   172,   172,   175,   175,   179,   179,   179,   183,   184,
     188,   189,   190,   194,   195,   199,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   236,   235,   254,   255,   259,   260,   264,
     265
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
  "RETICENCIAS", "NIL", "FALSO", "VERDADEIRO", "LOCAL", "IF", "THEN",
  "ELSE", "ELSEIF", "DO", "END", "WHILE", "REPEAT", "UNTIL", "FOR",
  "FUNCTION", "RETURN", "NUMERO", "IDENTIFICADOR", "MENOR_QUE",
  "MAIOR_QUE", "IGUALDADE", "AND", "OR", "MAIS", "MENOS", "MULTIPLICACAO",
  "DIVISAO", "NOT", "$accept", "programa", "lista_comandos", "comando",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "variavel",
  "definicao_variavel", "lista_atribuicao", "lista_variaveis",
  "bloco_escopo", "$@9", "comando_condicional", "$@10", "$@11",
  "comando_if", "$@12", "comando_elseif", "$@13", "$@14", "lista_elseif",
  "lista_parametros", "lista_expressoes", "expressao", "chamada_funcao",
  "$@15", "argumentos", "corpo_funcao", "retorno", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-96)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     197,   -17,    75,   -96,   -96,   -96,   -96,    -4,    21,    17,
     -96,   182,    11,   -96,   -96,    14,     4,   -96,    18,    19,
      75,   -96,   -96,   -96,   -96,    21,    75,    75,   141,   -96,
     197,    75,   197,    19,    43,    48,   -96,   197,    75,    40,
     -96,    75,    19,   -96,   -96,   -96,    53,    56,    43,   -96,
      33,   -96,   -96,   -96,   151,     6,   -96,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    59,    57,   141,   -96,
      73,    27,   -96,    41,   -96,    40,   -96,   113,   -96,   141,
      74,   197,    75,   -96,   -96,   -96,    19,   -96,    97,    97,
      97,   -24,   -24,     6,     6,   -96,   -96,   197,   -96,    62,
      66,    75,   197,   -96,    85,    86,    84,   -96,    87,   -96,
      75,    75,   -96,   141,   197,   -96,   -96,   -96,    75,   122,
      77,    19,    88,   197,   -96,   -96,   141,    78,   -96,   141,
     -96,   -96,   -96,    79,   197,    75,   -96,   -96,   132,    75,
     141,    62,   -96
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,     0,    35,    14,    17,    22,     0,    28,     0,
       2,     3,     0,    10,    13,     0,    37,    21,     0,     0,
       0,    59,    57,    58,    56,    55,     0,     0,    43,    71,
       0,     0,     0,     0,     0,     0,     1,     4,    79,     5,
       7,     0,     0,    20,    38,    45,    49,    40,     0,    28,
      33,    12,    29,    30,     0,    69,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    18,
       0,     0,    26,     0,    74,     6,    80,    53,     8,    31,
       0,     0,     0,    48,    41,    27,     0,    72,    66,    67,
      68,    64,    65,    62,    63,    60,    61,     0,    36,     0,
       0,     0,     0,    52,    33,    50,     0,    75,     0,     9,
       0,     0,    39,    46,     0,    34,    44,    16,     0,     0,
       0,     0,     0,     0,    76,    54,    32,     0,    42,    19,
      23,    77,    51,     0,     0,     0,    78,    47,     0,     0,
      24,     0,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,    -9,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,    -3,   -96,   -16,    -6,   -95,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,    58,   -96,   -68,    -2,
       1,   -96,   -96,    54,   -32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    11,    19,    31,    99,    32,   100,    33,
     135,   141,    12,    51,    13,   115,    14,    30,    15,    81,
     114,    16,    66,    46,    82,   127,    47,   106,    76,    77,
      29,    35,    74,    72,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    17,    39,    52,   117,   108,    18,    78,    62,    63,
      64,    65,    17,    53,    41,    42,    50,    36,    54,    44,
      45,    67,    34,    69,    55,    56,    80,   -73,    75,    68,
      70,    17,    43,    17,   102,   103,    41,    86,    17,    79,
      64,    65,   125,   109,    48,    49,   142,    20,   107,    71,
      21,    22,    23,    49,    73,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    38,   105,    24,    25,   104,    45,
      80,    84,   112,    97,    26,    98,   101,    27,   111,     3,
     113,    20,    17,    50,    21,    22,    23,   118,   116,   121,
     122,   123,   134,   120,   124,   131,   132,   136,    17,   119,
      24,    25,    85,    17,    83,   128,     0,     0,    26,   126,
       0,    27,     0,     0,   133,    17,   129,   110,   104,     0,
       0,     0,     0,     0,    17,   137,   130,    60,    61,    62,
      63,    64,    65,   138,     0,    17,   139,   140,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    87,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    37,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     3,
       0,     4,     5,     0,     6,     7,    38,     0,     8,     1,
       2,     0,     0,     0,     3,     0,     4,     5,     0,     6,
       7,     0,     0,     8
};

static const yytype_int16 yycheck[] =
{
       2,     0,    11,    19,    99,    73,    23,    39,    32,    33,
      34,    35,    11,    19,     3,     4,    19,     0,    20,    15,
      16,    30,    26,    32,    26,    27,    42,     6,    37,    31,
      33,    30,    18,    32,     7,     8,     3,     4,    37,    41,
      34,    35,   110,    75,    26,    26,   141,     6,     7,     6,
       9,    10,    11,    26,     6,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    24,    71,    25,    26,    71,    16,
      86,    15,    81,    14,    33,    18,     3,    36,     4,    17,
      82,     6,    81,    86,     9,    10,    11,    21,    97,     4,
       4,     7,    14,   102,     7,    18,     8,    18,    97,   101,
      25,    26,    48,   102,    46,   114,    -1,    -1,    33,   111,
      -1,    36,    -1,    -1,   123,   114,   118,     4,   121,    -1,
      -1,    -1,    -1,    -1,   123,   134,     4,    30,    31,    32,
      33,    34,    35,   135,    -1,   134,     4,   139,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     7,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    -1,    -1,    -1,    17,
      -1,    19,    20,    -1,    22,    23,    24,    -1,    26,    12,
      13,    -1,    -1,    -1,    17,    -1,    19,    20,    -1,    22,
      23,    -1,    -1,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    17,    19,    20,    22,    23,    26,    38,
      39,    40,    49,    51,    53,    55,    58,    67,    23,    41,
       6,     9,    10,    11,    25,    26,    33,    36,    66,    67,
      54,    42,    44,    46,    26,    68,     0,     5,    24,    39,
      71,     3,     4,    18,    15,    16,    60,    63,    26,    26,
      49,    50,    51,    52,    66,    66,    66,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    59,    39,    66,    39,
      49,     6,    70,     6,    69,    39,    65,    66,    71,    66,
      51,    56,    61,    63,    15,    70,     4,     7,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    14,    18,    43,
      45,     3,     7,     8,    49,    52,    64,     7,    65,    71,
       4,     4,    39,    66,    57,    52,    39,    53,    21,    66,
      39,     4,     4,     7,     7,    65,    66,    62,    39,    66,
       4,    18,     8,    39,    14,    47,    18,    39,    66,     4,
      66,    48,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    39,    39,    39,
      40,    41,    40,    40,    42,    43,    40,    44,    45,    40,
      40,    40,    46,    47,    48,    40,    40,    40,    49,    50,
      50,    51,    51,    52,    52,    54,    53,    55,    56,    55,
      55,    57,    55,    59,    58,    61,    62,    60,    63,    63,
      64,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    68,    67,    69,    69,    70,    70,    71,
      71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     3,     2,     3,     4,
       1,     0,     3,     1,     0,     0,     5,     0,     0,     6,
       2,     1,     0,     0,     0,    12,     3,     4,     1,     1,
       1,     3,     5,     1,     3,     0,     4,     1,     0,     4,
       2,     0,     5,     0,     5,     0,     0,     6,     2,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     3,     0,     3,     2,     3,     4,     5,     1,
       2
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
  case 2: /* programa: lista_comandos  */
#line 100 "source/sintatico.y"
    { 
        printf("\nPrograma sintaticamente CORRETO!\n"); 

        if (semantic_erros != 0) {
            printf("\nPrograma semanticamente INCORRETO! (%d erros)\n\n", semantic_erros); 
        } else {
            printf("\nPrograma semanticamente CORRETO!\n\n"); 
            gen_object_code(yyout); 
        }
    }
#line 1709 "build/sintatico.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 124 "source/sintatico.y"
            { in_local_definition = true; }
#line 1715 "build/sintatico.tab.c"
    break;

  case 12: /* comando: LOCAL $@1 definicao_variavel  */
#line 124 "source/sintatico.y"
                                                               { in_local_definition = false; }
#line 1721 "build/sintatico.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 126 "source/sintatico.y"
            { add_label(); }
#line 1727 "build/sintatico.tab.c"
    break;

  case 15: /* $@3: %empty  */
#line 126 "source/sintatico.y"
                                       { add_label(); skip_code_position(2); }
#line 1733 "build/sintatico.tab.c"
    break;

  case 16: /* comando: WHILE $@2 expressao $@3 bloco_escopo  */
#line 126 "source/sintatico.y"
                                                                                            { gen_while(); }
#line 1739 "build/sintatico.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 127 "source/sintatico.y"
             { add_label(); enter_scope(); }
#line 1745 "build/sintatico.tab.c"
    break;

  case 18: /* $@5: %empty  */
#line 127 "source/sintatico.y"
                                                            { exit_scope(); }
#line 1751 "build/sintatico.tab.c"
    break;

  case 19: /* comando: REPEAT $@4 lista_comandos $@5 UNTIL expressao  */
#line 127 "source/sintatico.y"
                                                                                              { gen_repeat(); }
#line 1757 "build/sintatico.tab.c"
    break;

  case 20: /* comando: comando_condicional END  */
#line 128 "source/sintatico.y"
                              { gen_if_end_jump((yyvsp[-1].ival)); }
#line 1763 "build/sintatico.tab.c"
    break;

  case 22: /* $@6: %empty  */
#line 130 "source/sintatico.y"
          { in_local_definition = true; enter_scope(); }
#line 1769 "build/sintatico.tab.c"
    break;

  case 23: /* $@7: %empty  */
#line 131 "source/sintatico.y"
    { 
        gen_assignment_for_pending_var(); 
        in_local_definition = false; 
    }
#line 1778 "build/sintatico.tab.c"
    break;

  case 24: /* $@8: %empty  */
#line 135 "source/sintatico.y"
                                { add_label(); }
#line 1784 "build/sintatico.tab.c"
    break;

  case 25: /* comando: FOR $@6 variavel ATRIBUICAO expressao VIRGULA $@7 expressao VIRGULA expressao $@8 bloco_escopo  */
#line 136 "source/sintatico.y"
    { 
        gen_for(search_variable((yyvsp[-9].sval), current_scope_level)); 
        exit_scope(); 
    }
#line 1793 "build/sintatico.tab.c"
    break;

  case 28: /* variavel: IDENTIFICADOR  */
#line 146 "source/sintatico.y"
    { 
        insert_variable((yyvsp[0].sval), in_local_definition ? current_scope_level : 0, current_line_number++); 
        add_pending_variable((yyvsp[0].sval));
        (yyval.sval) = (yyvsp[0].sval);
    }
#line 1803 "build/sintatico.tab.c"
    break;

  case 31: /* lista_atribuicao: variavel ATRIBUICAO expressao  */
#line 157 "source/sintatico.y"
                                                            { gen_assignment_for_pending_var(); }
#line 1809 "build/sintatico.tab.c"
    break;

  case 32: /* lista_atribuicao: variavel VIRGULA lista_atribuicao VIRGULA expressao  */
#line 158 "source/sintatico.y"
                                                            { gen_assignment_for_pending_var(); }
#line 1815 "build/sintatico.tab.c"
    break;

  case 33: /* lista_variaveis: variavel  */
#line 162 "source/sintatico.y"
                                            { gen_num(0); gen_assignment_for_pending_var(); /* A variavel recebe 0 */ }
#line 1821 "build/sintatico.tab.c"
    break;

  case 34: /* lista_variaveis: variavel VIRGULA lista_variaveis  */
#line 163 "source/sintatico.y"
                                            { gen_num(0); gen_assignment_for_pending_var(); /* A variavel recebe 0 */ }
#line 1827 "build/sintatico.tab.c"
    break;

  case 35: /* $@9: %empty  */
#line 166 "source/sintatico.y"
       { enter_scope(); }
#line 1833 "build/sintatico.tab.c"
    break;

  case 36: /* bloco_escopo: DO $@9 lista_comandos END  */
#line 166 "source/sintatico.y"
                                             { exit_scope(); }
#line 1839 "build/sintatico.tab.c"
    break;

  case 37: /* comando_condicional: comando_if  */
#line 169 "source/sintatico.y"
                                                                          { (yyval.ival) = 1; gen_if_exp_jump(); }
#line 1845 "build/sintatico.tab.c"
    break;

  case 38: /* $@10: %empty  */
#line 170 "source/sintatico.y"
                      { gen_if_exp_jump(); }
#line 1851 "build/sintatico.tab.c"
    break;

  case 39: /* comando_condicional: comando_if ELSE $@10 lista_comandos  */
#line 170 "source/sintatico.y"
                                                                          { (yyval.ival) = 1; }
#line 1857 "build/sintatico.tab.c"
    break;

  case 40: /* comando_condicional: comando_if lista_elseif  */
#line 171 "source/sintatico.y"
                                                                          { (yyval.ival) = 1 + (yyvsp[0].ival); gen_if_exp_jump(); }
#line 1863 "build/sintatico.tab.c"
    break;

  case 41: /* $@11: %empty  */
#line 172 "source/sintatico.y"
                                   { gen_if_exp_jump(); }
#line 1869 "build/sintatico.tab.c"
    break;

  case 42: /* comando_condicional: comando_if lista_elseif ELSE $@11 lista_comandos  */
#line 172 "source/sintatico.y"
                                                                          { (yyval.ival) = 1 + (yyvsp[-3].ival); }
#line 1875 "build/sintatico.tab.c"
    break;

  case 43: /* $@12: %empty  */
#line 175 "source/sintatico.y"
                 {  add_label(); skip_code_position(2); enter_scope(); }
#line 1881 "build/sintatico.tab.c"
    break;

  case 44: /* comando_if: IF expressao $@12 THEN lista_comandos  */
#line 176 "source/sintatico.y"
                            { exit_scope(); add_label(); skip_code_position(1); }
#line 1887 "build/sintatico.tab.c"
    break;

  case 45: /* $@13: %empty  */
#line 179 "source/sintatico.y"
           { gen_if_exp_jump(); }
#line 1893 "build/sintatico.tab.c"
    break;

  case 46: /* $@14: %empty  */
#line 179 "source/sintatico.y"
                                            { add_label(); skip_code_position(2); enter_scope(); }
#line 1899 "build/sintatico.tab.c"
    break;

  case 47: /* comando_elseif: ELSEIF $@13 expressao $@14 THEN lista_comandos  */
#line 180 "source/sintatico.y"
                            { exit_scope(); add_label(); skip_code_position(1); }
#line 1905 "build/sintatico.tab.c"
    break;

  case 48: /* lista_elseif: comando_elseif lista_elseif  */
#line 183 "source/sintatico.y"
                                      { (yyval.ival) = 1 + (yyvsp[0].ival); }
#line 1911 "build/sintatico.tab.c"
    break;

  case 49: /* lista_elseif: comando_elseif  */
#line 184 "source/sintatico.y"
                                      { (yyval.ival) = 1; }
#line 1917 "build/sintatico.tab.c"
    break;

  case 53: /* lista_expressoes: expressao  */
#line 194 "source/sintatico.y"
                                                { if (in_print_call) gen_print(); }
#line 1923 "build/sintatico.tab.c"
    break;

  case 54: /* lista_expressoes: expressao VIRGULA lista_expressoes  */
#line 195 "source/sintatico.y"
                                                { if (in_print_call) gen_print(); }
#line 1929 "build/sintatico.tab.c"
    break;

  case 55: /* expressao: IDENTIFICADOR  */
#line 200 "source/sintatico.y"
    { 
        variable* var = search_variable((yyvsp[0].sval), current_scope_level);

        if (var == NULL) {
            printf(
                "\n*** ERRO SEMÂNTICO | Linha %d: Variável '%s' não foi declarada nesse escopo!\n", 
                current_line_number, (yyvsp[0].sval)
            );
            semantic_erros++;
        } else {
            var->is_used = true;

            gen_variable_value(var);
        }
    }
#line 1949 "build/sintatico.tab.c"
    break;

  case 56: /* expressao: NUMERO  */
#line 215 "source/sintatico.y"
                                                { gen_num((yyvsp[0].ival)); }
#line 1955 "build/sintatico.tab.c"
    break;

  case 57: /* expressao: FALSO  */
#line 216 "source/sintatico.y"
                                                { gen_num(0); }
#line 1961 "build/sintatico.tab.c"
    break;

  case 58: /* expressao: VERDADEIRO  */
#line 217 "source/sintatico.y"
                                                { gen_num(1); }
#line 1967 "build/sintatico.tab.c"
    break;

  case 59: /* expressao: NIL  */
#line 218 "source/sintatico.y"
                                                { gen_num(0); }
#line 1973 "build/sintatico.tab.c"
    break;

  case 60: /* expressao: expressao MULTIPLICACAO expressao  */
#line 219 "source/sintatico.y"
                                                { gen_binary_operation(OP_MUL); }
#line 1979 "build/sintatico.tab.c"
    break;

  case 61: /* expressao: expressao DIVISAO expressao  */
#line 220 "source/sintatico.y"
                                                { gen_binary_operation(OP_DIV); }
#line 1985 "build/sintatico.tab.c"
    break;

  case 62: /* expressao: expressao MAIS expressao  */
#line 221 "source/sintatico.y"
                                                { gen_binary_operation(OP_ADD); }
#line 1991 "build/sintatico.tab.c"
    break;

  case 63: /* expressao: expressao MENOS expressao  */
#line 222 "source/sintatico.y"
                                                { gen_binary_operation(OP_SUB); }
#line 1997 "build/sintatico.tab.c"
    break;

  case 64: /* expressao: expressao AND expressao  */
#line 223 "source/sintatico.y"
                                                { gen_binary_operation(OP_AND); }
#line 2003 "build/sintatico.tab.c"
    break;

  case 65: /* expressao: expressao OR expressao  */
#line 224 "source/sintatico.y"
                                                { gen_binary_operation(OP_OR); }
#line 2009 "build/sintatico.tab.c"
    break;

  case 66: /* expressao: expressao MENOR_QUE expressao  */
#line 225 "source/sintatico.y"
                                                { gen_binary_operation(OP_LESS_THAN); }
#line 2015 "build/sintatico.tab.c"
    break;

  case 67: /* expressao: expressao MAIOR_QUE expressao  */
#line 226 "source/sintatico.y"
                                                { gen_binary_operation(OP_GREATER_THAN); }
#line 2021 "build/sintatico.tab.c"
    break;

  case 68: /* expressao: expressao IGUALDADE expressao  */
#line 227 "source/sintatico.y"
                                                { gen_binary_operation(OP_EQUALITY); }
#line 2027 "build/sintatico.tab.c"
    break;

  case 69: /* expressao: MENOS expressao  */
#line 228 "source/sintatico.y"
                                                { gen_unary_operation(OP_NEG); }
#line 2033 "build/sintatico.tab.c"
    break;

  case 70: /* expressao: NOT expressao  */
#line 229 "source/sintatico.y"
                                                { gen_unary_operation(OP_NOT); }
#line 2039 "build/sintatico.tab.c"
    break;

  case 71: /* expressao: chamada_funcao  */
#line 230 "source/sintatico.y"
                                                { if (strcmp((yyvsp[0].sval), "read") != 0) gen_num(0); }
#line 2045 "build/sintatico.tab.c"
    break;

  case 73: /* $@15: %empty  */
#line 236 "source/sintatico.y"
    {
        if (strcmp((yyvsp[0].sval), "print") == 0) {
            in_print_call = true; 
        } else if (strcmp((yyvsp[0].sval), "read") == 0) {
            gen_read();
        }
    }
#line 2057 "build/sintatico.tab.c"
    break;

  case 74: /* chamada_funcao: IDENTIFICADOR $@15 argumentos  */
#line 244 "source/sintatico.y"
    {
        if (strcmp((yyvsp[-2].sval), "print") == 0) {
            in_print_call = false; 
        }

        (yyval.sval) = strdup((yyvsp[-2].sval));
    }
#line 2069 "build/sintatico.tab.c"
    break;


#line 2073 "build/sintatico.tab.c"

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

#line 267 "source/sintatico.y"


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

    verify_not_used_variables();

    fclose(yyin);
    fclose(yyout);
}
