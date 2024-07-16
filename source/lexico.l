%{
#include "sintatico.tab.h"
%}


%%
"begin" { return INICIO; }
"end"   { return FIM; }
[A-E]   { return VARIAVEL; }
":="    { return ATRIB; }
"+"     { return MAIS; }
"-"     { return MENOS; }
[;]     { return PONTUACAO; }
[ \t]+  {; }
\n      {; }
.       { printf("Erro: token inválido: %s\n", yytext); exit(1); }
%%

int yywrap() {
    return 1;
}