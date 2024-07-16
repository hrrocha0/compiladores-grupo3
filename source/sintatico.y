%{
#include <stdio.h> 
%}

%token INICIO
%token FIM
%token VARIAVEL
%token ATRIB
%token MAIS
%token MENOS
%token PONTUACAO

%%
programa:    INICIO lista_comandos FIM { printf("Programa sintaticamente correto!\n"); }
          ;

lista_comandos: comando
              | comando PONTUACAO lista_comandos
              ;

comando:     VARIAVEL ATRIB expressao
           ;

expressao:   VARIAVEL MAIS VARIAVEL
           | VARIAVEL MENOS VARIAVEL
           | VARIAVEL
           ;
%%

int main () 
{
	yyparse ();
}
yyerror (s) /* Called by yyparse on error */
	char *s;
{
	printf("Problema com a analise sintatica! %s\n", s);
}

