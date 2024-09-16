/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_SINTATICO_TAB_H_INCLUDED
# define YY_YY_BUILD_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ATRIBUICAO = 258,              /* ATRIBUICAO  */
    VIRGULA = 259,                 /* VIRGULA  */
    PONTO_VIRGULA = 260,           /* PONTO_VIRGULA  */
    PARENTESE_ESQUERDO = 261,      /* PARENTESE_ESQUERDO  */
    PARENTESE_DIREITO = 262,       /* PARENTESE_DIREITO  */
    RETICENCIAS = 263,             /* RETICENCIAS  */
    NIL = 264,                     /* NIL  */
    FALSO = 265,                   /* FALSO  */
    VERDADEIRO = 266,              /* VERDADEIRO  */
    LOCAL = 267,                   /* LOCAL  */
    IF = 268,                      /* IF  */
    THEN = 269,                    /* THEN  */
    ELSE = 270,                    /* ELSE  */
    ELSEIF = 271,                  /* ELSEIF  */
    DO = 272,                      /* DO  */
    END = 273,                     /* END  */
    WHILE = 274,                   /* WHILE  */
    REPEAT = 275,                  /* REPEAT  */
    UNTIL = 276,                   /* UNTIL  */
    FOR = 277,                     /* FOR  */
    FUNCTION = 278,                /* FUNCTION  */
    RETURN = 279,                  /* RETURN  */
    NUMERO = 280,                  /* NUMERO  */
    IDENTIFICADOR = 281,           /* IDENTIFICADOR  */
    MENOR_QUE = 282,               /* MENOR_QUE  */
    MAIOR_QUE = 283,               /* MAIOR_QUE  */
    IGUALDADE = 284,               /* IGUALDADE  */
    AND = 285,                     /* AND  */
    OR = 286,                      /* OR  */
    MAIS = 287,                    /* MAIS  */
    MENOS = 288,                   /* MENOS  */
    MULTIPLICACAO = 289,           /* MULTIPLICACAO  */
    DIVISAO = 290,                 /* DIVISAO  */
    NOT = 291                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 68 "source/sintatico.y"

    int ival;
    char* sval;

#line 105 "build/sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_BUILD_SINTATICO_TAB_H_INCLUDED  */
