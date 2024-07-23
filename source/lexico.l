%{
#include "sintatico.tab.h"

int num_linha_atual = 1;
int contar_linhas(const char *str);
%}

numero                      [0-9]+(\.[0-9]+)?
string_aspas_simples        \'([^\\\']|\\.)*\'
string_aspas_duplas         \"([^\\\"]|\\.)*\"
identificador               [a-zA-Z_][a-zA-Z0-9_]*
comentario                  --[^\n]*
comentario_multi_linhas     --\[\[(.|\n)*?--\]\]

%%
"-"                         { return MENOS; }
"+"                         { return MAIS; }
"*"                         { return MULTIPLICACAO; }
"/"                         { return DIVISAO; }
"="                         { return ATRIBUICAO; }
","                         { return VIRGULA; }
";"                         { return PONTO_VIRGULA; }
"nil"                       { return NIL; }
"false"                     { return FALSO; }
"true"                      { return VERDADEIRO; }
"and"                       { return AND; }
"or"                        { return OR; }
"not"                       { return NOT; }
"local"                     { return LOCAL; }
{numero}                    { return NUMERO; }
{string_aspas_simples}      { return STRING; }
{string_aspas_duplas}       { return STRING; }
{identificador}             { return IDENTIFICADOR; }
{comentario}                { ; }
{comentario_multi_linhas}   { num_linha_atual += contar_linhas(yytext); }
\n                          { num_linha_atual++; }
[ \t]+                      { ; }
.                           { printf("*** ERRO | LINHA %d: Token inválido: %s\n", num_linha_atual, yytext); exit(1); }
%%

int yywrap() {
    return 1;
}

void yyerror(const char *s) {
    printf("*** ERRO | LINHA %d: %s\n", num_linha_atual, s);
}

int contar_linhas(const char *str) {
    int num_linhas = 0;

    int i = 0;     
    while (yytext[i]) { 
        if (yytext[i] == '\n') { 
            num_linhas++; 
        } 
        i++; 
    }

    return num_linhas;
}