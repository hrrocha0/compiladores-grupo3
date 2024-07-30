# Analisador lexico
flex -o build/lex.yy.c source/lexico.l

# Analisador sintatico
bison -o build/sintatico.tab.c -d source/sintatico.y

# Integração
gcc build/sintatico.tab.c build/lex.yy.c -o compilador -lfl
