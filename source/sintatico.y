%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../source/code_generator.h"

int yylex(void);
void yyerror(const char* s);

bool in_print_call;
bool read_call;

extern FILE* yyin;
extern FILE* yyout;
%}

%union {
    int ival;
    char* sval;
}

%locations
%define parse.error verbose

%token ATRIBUICAO VIRGULA PONTO_VIRGULA PARENTESE_ESQUERDO PARENTESE_DIREITO RETICENCIAS
%token NIL FALSO VERDADEIRO LOCAL IF THEN ELSE ELSEIF DO END WHILE REPEAT UNTIL FOR IN FUNCTION
%token <ival> NUMERO
%token <sval> IDENTIFICADOR

%left AND OR
%left MAIS MENOS
%left MULTIPLICACAO DIVISAO 
%left NOT

%type <ival> expressao

%%
programa: 
    lista_comandos { gen_halt(yyout); printf("\nPrograma sintaticamente correto!\n\n"); }
    ;

lista_comandos:
    comando
    | comando PONTO_VIRGULA
    | comando lista_comandos
    | comando PONTO_VIRGULA lista_comandos
    ;

comando: 
    lista_identificadores ATRIBUICAO lista_expressoes
    | DO lista_comandos END
    | WHILE expressao DO lista_comandos END
    | REPEAT lista_comandos UNTIL expressao
    | IF expressao THEN lista_comandos END
    | IF expressao THEN lista_comandos ELSE lista_comandos END
    | IF expressao THEN lista_comandos lista_elseif END
    | IF expressao THEN lista_comandos lista_elseif ELSE lista_comandos END
    | FOR IDENTIFICADOR ATRIBUICAO expressao VIRGULA lista_expressoes DO lista_comandos END
    | FOR lista_identificadores IN lista_expressoes DO lista_comandos END
    | FUNCTION IDENTIFICADOR corpo_funcao
    | LOCAL FUNCTION IDENTIFICADOR corpo_funcao
    | LOCAL lista_identificadores
    | LOCAL lista_identificadores ATRIBUICAO lista_expressoes
    | chamada_funcao
    ;

lista_elseif:
    lista_elseif lista_elseif
    | ELSEIF lista_comandos
    ;

lista_parametros:
    lista_identificadores
    | lista_identificadores VIRGULA RETICENCIAS
    | RETICENCIAS
    ;

lista_identificadores:
    IDENTIFICADOR
    | IDENTIFICADOR VIRGULA lista_identificadores
    ;

lista_expressoes:
    expressao                                   { if (in_print_call) gen_print_constant(yyout, $1); }
    | expressao VIRGULA lista_expressoes        { if (in_print_call) gen_print_constant(yyout, $1); }
    ;

expressao: 
    IDENTIFICADOR                               { $$ = 0; }
    | NUMERO                                    { $$ = $1; }
    | FALSO                                     { $$ = 0; }
    | VERDADEIRO                                { $$ = 1; }
    | NIL                                       { $$ = 0; }
    | expressao MULTIPLICACAO expressao         { $$ = $1 * $3; }
    | expressao DIVISAO expressao               { $$ = $1 / $3; }
    | expressao MAIS expressao                  { $$ = $1 + $3; }
    | expressao MENOS expressao                 { $$ = $1 - $3; }
    | expressao AND expressao                   { $$ = $1 & $3; }
    | expressao OR expressao                    { $$ = $1 | $3; }
    | MENOS expressao                           { $$ = -$2; }
    | NOT expressao                             { $$ = !$2; }
    ;

chamada_funcao:
    IDENTIFICADOR { if (strcmp($1, "print")) in_print_call = true; if(strcmp($1, "read")) read_call = true; } argumentos { in_print_call = false; read_call = false; }
    ;

argumentos:
    PARENTESE_ESQUERDO PARENTESE_DIREITO
    | PARENTESE_ESQUERDO lista_expressoes PARENTESE_DIREITO
    ;

corpo_funcao:
    PARENTESE_ESQUERDO PARENTESE_DIREITO lista_comandos END
    | PARENTESE_ESQUERDO lista_parametros PARENTESE_DIREITO lista_comandos END
%%

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

    fclose(yyin);
    fclose(yyout);
}