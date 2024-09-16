%{
#include "sintatico.tab.h"

extern int current_line_number;
int count_lines(const char* str);
%}

%state IN_COMMENT

numero                      [0-9]+(\.[0-9]+)?
identificador               [a-zA-Z_][a-zA-Z0-9_]*
comentario                  --[^\n]*

%%
<INITIAL>"--[["             { BEGIN(IN_COMMENT); }
<IN_COMMENT>"]]"            { BEGIN(INITIAL); }
<IN_COMMENT>[^\]\n]+
<IN_COMMENT>"]"
<IN_COMMENT>\n              { current_line_number++; }
"-"                         { return MENOS; }
"+"                         { return MAIS; }
"*"                         { return MULTIPLICACAO; }
"/"                         { return DIVISAO; }
"="                         { return ATRIBUICAO; }
","                         { return VIRGULA; }
";"                         { return PONTO_VIRGULA; }
"..."                       { return RETICENCIAS; }
"("                         { return PARENTESE_ESQUERDO; }
")"                         { return PARENTESE_DIREITO; }
"nil"                       { return NIL; }
"false"                     { return FALSO; }
"true"                      { return VERDADEIRO; }
"and"                       { return AND; }
"or"                        { return OR; }
"not"                       { return NOT; }
"<"                         { return MENOR_QUE; }
">"                         { return MAIOR_QUE; }
"=="                        { return IGUALDADE; }
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
"function"                  { return FUNCTION; }
"return"                    { return RETURN; }
{numero}                    { yylval.ival = atoi(yytext); return NUMERO; }
{identificador}             { yylval.sval = strdup(yytext); return IDENTIFICADOR; }
{comentario}                { ; }
[\r]*\n                     { current_line_number++; }
[ \t]+                      { ; }
.                           { printf("*** ERRO LÉXICO | LINHA %d: Token inválido: '%s'\n", current_line_number, yytext); exit(1); }
%%

int yywrap() {
    return 1;
}

void yyerror(const char *s) {
    printf("*** ERRO SINTÁTICO | LINHA %d: %s\n", current_line_number, s);
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