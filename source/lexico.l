%{
#include "sintatico.tab.h"

int current_line_number = 1;
int count_lines(const char* str);
%}

numero                      [0-9]+(\.[0-9]+)?
identificador               [a-zA-Z_][a-zA-Z0-9_]*
comentario                  --[^\n]*
comentario_multi_linhas     --\[\[(.|\n)*?\]\]

%%
"-"                         { return MENOS; }
"+"                         { return MAIS; }
"*"                         { return MULTIPLICACAO; }
"/"                         { return DIVISAO; }
"="                         { return ATRIBUICAO; }
","                         { return VIRGULA; }
";"                         { return PONTO_VIRGULA; }
"("                         { return PARENTESE_ESQUERDO; }
")"                         { return PARENTESE_DIREITO; }
"..."                       { return RETICENCIAS; }
"nil"                       { return NIL; }
"false"                     { return FALSO; }
"true"                      { return VERDADEIRO; }
"and"                       { return AND; }
"or"                        { return OR; }
"not"                       { return NOT; }
"local"                     { return LOCAL; }
"if"                        { return IF; }
"then"                      { return THEN; }
"else"                      { return ELSE; }
"elseif"                    { return ELSEIF; }
"do"                        { return DO; }
"end"                       { return END; }
"while"                     { return WHILE; }
"repeat"                    { return REPEAT; }
"until"                     { return UNTIL; }
"for"                       { return FOR; }
"in"                        { return IN; }
"function"                  { return FUNCTION; }
{numero}                    { yylval.ival = atoi(yytext); return NUMERO; }
{identificador}             { yylval.sval = yytext; return IDENTIFICADOR; }
{comentario}                { ; }
{comentario_multi_linhas}   { current_line_number += count_lines(yytext); }
[\r]*\n                     { current_line_number++; }
[ \t]+                      { ; }
.                           { printf("*** ERRO | LINHA %d: Token inválido: %s\n", current_line_number, yytext); exit(1); }
%%

int yywrap() {
    return 1;
}

void yyerror(const char *s) {
    printf("*** ERRO | LINHA %d: %s\n", current_line_number, s);
}

int count_lines(const char* str) {
    int line_count = 0;

    int i = 0;     
    while (yytext[i]) { 
        if (yytext[i] == '\n') { 
            line_count++; 
        } 
        i++; 
    }

    return line_count;
}