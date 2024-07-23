# Grupo 3 - Compiladores 2024.1

O compilador desenvolvido é baseado na linguagem de programação [Lua](https://www.lua.org/manual/5.1/manual.html) a partir da gramática BNF disponibilizada neste [link](https://parrot.github.io/parrot-docs0/0.4.7/html/languages/lua/doc/lua51.bnf.html), com base nos *slides* oferecidos pela professora.

## Analisador Sintático

### Versão 1

A primeira versão do analisador sintático incorpora os tokens reconhecidos pela primeira versão do [Analisador Léxico](source/lexico.l), a partir da seguinte gramática BNF, adaptada da gramática da linguagem Lua:

```bnf
<programa> ::= <lista_comandos>

<lista_comandos> ::= <comando>
        | <comando> ";"
        | <comando> <lista_comandos>
        | <comando> ";" <lista_comandos>

<comando> ::= <lista_identificadores> ";" <lista_expressoes>
        | "local" <lista_identificadores> 
        | "local" <lista_identificadores> "=" <lista_expressoes>

<lista_identificadores> ::= IDENTIFICADOR
        | IDENTIFICADOR "," <lista_identificadores>

<lista_expressoes> ::= <expressao>
        | <expressao> "," <lista_expressoes>

<expressao> ::= IDENTIFICADOR
        | NUMERO
        | STRING
        | "nil"
        | "false"
        | "true"
        | <expressao> "+" <expressao>
        | <expressao> "-" <expressao>
        | <expressao> "*" <expressao>
        | <expressao> "/" <expressao>
        | "not <expressao>
        | <expressao> "and" <expressao>
        | <expressao> "or" <expressao>
        | "-" <expressao>
```

## Flex e Bison

Para compilar o código, Flex e Bison devem estar instalados. Para instalá-los no Linux ou no Windows (requer WSL), basta executar os seguindes comandos:

### Flex

```bash
sudo apt-get install flex
```

### Bison

```bash
apt install bison
```

## Compilação

A compilação pode ser realizada pelo Linux ou pelo Windows, caso o WSL esteja instalado. É necessário que estejam instalados o Flex, o Bison e o GCC. Em seguida, basta executar o arquivo [build.sh](./build.sh). Alternativamente, é possível executar manualmente os comandos de compilação:

### Analisador Léxico

```bash
flex -o build/lex.yy.c source/lexico.l
```

### Analisador Sintático

```bash
bison -o build/sintatico.tab.c -d source/sintatico.y
```

### Integração

```bash
gcc build/sintatico.tab.c build/lex.yy.c -o sintatico -lfl
```

## Execução

Para realizar a análise sintática de um arquivo de código fonte, pode ser usado o seguinde comando:

```bash
./sintatico < $file
```

Por exemplo, executando o analisador para o arquivo de teste [teste_sintatico_sem_erros.lua](/tests/teste_sintatico_sem_erros.lua):

```bash
./sintatico < tests/teste_sintatico_sem_erros.lua
```

É obtida a mensagem:

`Programa sintaticamente correto!`

## Referências

- https://www.lua.org/manual/5.4/manual.html
- https://www.olivroqueaprende.com/WDK/Lua.html
- https://parrot.github.io/parrot-docs0/0.4.7/html/languages/lua/doc/lua51.bnf.html
