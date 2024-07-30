%{
#include <stdio.h>

int yylex(void);
void yyerror(const char* s);
%}

%locations
%define parse.error verbose

%token ATRIBUICAO VIRGULA PONTO_VIRGULA DOIS_PONTOS PARENTESE_ESQUERDO PARENTESE_DIREITO
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
    | chamada_funcao
    ;

lista_identificadores:
    IDENTIFICADOR
    | IDENTIFICADOR VIRGULA lista_identificadores
    ;

lista_expressoes:
    expressao
    | expressao VIRGULA lista_expressoes
    ;

variavel:
    IDENTIFICADOR
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

chamada_funcao:
    expressao_prefixa argumentos
    | expressao_prefixa DOIS_PONTOS IDENTIFICADOR argumentos
    ;

expressao_prefixa:
    variavel
    | chamada_funcao
    | PARENTESE_ESQUERDO expressao PARENTESE_DIREITO
    ;

argumentos:
    PARENTESE_ESQUERDO PARENTESE_DIREITO
    | PARENTESE_ESQUERDO lista_expressoes PARENTESE_DIREITO
    | STRING
    ;
%%

int main() {
    yyparse();
}