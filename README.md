# Grupo 3 - Compiladores 2024.1

O compilador desenvolvido é baseado na linguagem de programação [Lua](https://www.lua.org/manual/5.1/manual.html) a partir da gramática BNF disponibilizada neste [link](https://parrot.github.io/parrot-docs0/0.4.7/html/languages/lua/doc/lua51.bnf.html), com base nos *slides* oferecidos pela professora.

## Analisador Sintático

### Versão 1

A primeira versão do analisador sintático incorpora os tokens reconhecidos pela primeira versão do [Analisador Léxico](source/lexico.l), incorporando o comando de atribuição a partir da seguinte gramática BNF, adaptada da gramática de exemplo dos *slides*:

```bnf
INICIO      ::= "begin"
FIM         ::= "end"
VARIAVEL    ::= [A-E]
ATRIB       ::= ":="
MAIS        ::= "+"
MENOS       ::= "-"
PONTUACAO   ::= ";"

<programa> ::= INICIO <lista_comandos> FIM

<lista_comandos> ::= <comando>
                   | <comando> PONTUACAO <lista_comandos>

<comando> ::= VARIAVEL ATRIB <expressao>

<expressao> ::= VARIAVEL MAIS VARIAVEL
              | VARIAVEL MENOS VARIAVEL
              | VARIAVEL
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
flex -o source/lex.yy.c source/lexico.l
```

### Analisador Sintático

```bash
`bison -o source/sintatico.tab.c -d source/sintatico.y`
```

### Integração

```bash
gcc source/sintatico.tab.c source/lex.yy.c -o sintatico -lfl
```

## Execução

Para realizar a análise sintática de um arquivo de código fonte, pode ser usado o seguinde comando:

```bash
./sintatico < input/$file}
```

Por exemplo, executando o analisador para o arquivo de teste [teste.lua](/input/teste.lua):

```bash
./sintatico < input/teste.lua
```

É obtida a mensagem:

`Programa sintaticamente correto!`