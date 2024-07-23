%{
#include <stdio.h>

int yylex(void);
void yyerror(const char* s);
%}

%locations
%define parse.error verbose

%token ATRIBUICAO VIRGULA PONTO_VIRGULA
%token NUMERO STRING NIL FALSO VERDADEIRO LOCAL
%token IDENTIFICADOR

%left AND OR
%left MAIS MENOS
%left MULTIPLICACAO DIVISAO 
%left NOT

%%
programa: 
    lista_comandos { printf("Programa sintaticamente correto!\n"); }
    ;

lista_comandos:
    comando
    | comando PONTO_VIRGULA
    | comando lista_comandos
    | comando PONTO_VIRGULA lista_comandos
    ;

comando: 
    lista_identificadores ATRIBUICAO lista_expressoes
    | LOCAL lista_identificadores
    | LOCAL lista_identificadores ATRIBUICAO lista_expressoes
    ;

lista_identificadores:
    IDENTIFICADOR
    | IDENTIFICADOR VIRGULA lista_identificadores
    ;

lista_expressoes:
    expressao
    | expressao VIRGULA lista_expressoes
    ;

expressao: 
    IDENTIFICADOR
    | NUMERO
    | STRING
    | FALSO
    | VERDADEIRO
    | NIL
    | expressao MULTIPLICACAO expressao
    | expressao DIVISAO expressao
    | expressao MAIS expressao
    | expressao MENOS expressao
    | expressao AND expressao
    | expressao OR expressao
    | MENOS expressao
    | NOT expressao
    ;
%%

int main() {
    yyparse();
}