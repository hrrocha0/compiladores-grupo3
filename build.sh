# Analisador lexico
flex -o source/lex.yy.c source/lexico.l

# Analisador sintatico
bison -o source/sintatico.tab.c -d source/sintatico.y

# Integração
gcc source/sintatico.tab.c source/lex.yy.c -o sintatico -lfl
