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
        | <chamada_funcao>

<lista_identificadores> ::= IDENTIFICADOR
        | IDENTIFICADOR "," <lista_identificadores>

<lista_expressoes> ::= <expressao>
        | <expressao> "," <lista_expressoes>

<variavel> ::= IDENTIFICADOR

<expressao> ::= IDENTIFICADOR
        | NUMERO
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

<chamada_funcao> ::= IDENTIFICADOR <argumentos>

<argumentos> ::= "()"
        | "(" <lista_expressoes> ")"

```

## Gerador de Código

O compilador é capaz de gerar código objeto para a [Tiny Machine](http://www.cs.sjsu.edu/~louden/cmptext/) do Kenneth C. Louden.

### Versão 1

A primeira versão é capaz de reconhecer e gerar código apenas para o comando `print`. Nesta versão inicial, o `print` só consegue imprimir constantes numéricas, portanto, para que isso seja possível, o compilador considera que todas as variáveis, "nil" e "false" têm valor 0, enquanto "true" tem valor 1.

Por exemplo:

```
print(34)
print(-10)
print(-10 + 5)
print(1 + a + 30 + 40)
print(false or not 1 and 0 and true)
print(1 / 5 + 2 * 4 + 1)
print(1 / 2 - 5 * b + 8 + -7 / 3 + a)
```

É traduzido para:

```
0:  LDC 0,34(0)		* Reg[0] = 34
1:  OUT 0,0,0 	 	* Reg[0] -> saída padrão
2:  LDC 0,-10(0)	* Reg[0] = -10
3:  OUT 0,0,0 	 	* Reg[0] -> saída padrão
4:  LDC 0,-5(0)		* Reg[0] = -5
5:  OUT 0,0,0 	 	* Reg[0] -> saída padrão
6:  LDC 0,71(0)		* Reg[0] = 71
7:  OUT 0,0,0 	 	* Reg[0] -> saída padrão
8:  LDC 0,0(0)		* Reg[0] = 0
9:  OUT 0,0,0 	 	* Reg[0] -> saída padrão
10:  LDC 0,9(0)		* Reg[0] = 9
11:  OUT 0,0,0 	 	* Reg[0] -> saída padrão
12:  LDC 0,6(0)		* Reg[0] = 6
13:  OUT 0,0,0 	 	* Reg[0] -> saída padrão
14:  HALT 0,0,0
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
gcc build/sintatico.tab.c build/lex.yy.c -o compilador -lfl
```

## Execução

Você pode executar o compilador usando o seguinte comando:

```
./compilador ./<seu_programa>.lua
```

O compilador vai ler o arquivo e realizar a análise sintática. Se tudo estiver correto é obtida a mensagem:

`Programa sintaticamente correto!`

Além disso, caso o programa contenha algum dos comandos descritos na secção [Gerador de Código](#gerador-de-código), o compilador também irá gerar o código objeto para a Tiny Machine.

Você pode especificar o arquivo que irá receber o código objeto da seguinte forma:

```
./compilador ./<seu_programa>.lua ./<seu_arquivo_objeto>.tm
```

Esse arquivo pode então ser carregado e simulado através da Tiny Machine disponível no repositório:

```
./TINY_MACHINE ./<seu_arquivo_objeto>.tm
```

## Referências

- https://www.lua.org/manual/5.4/manual.html
- https://www.olivroqueaprende.com/WDK/Lua.html
- https://parrot.github.io/parrot-docs0/0.4.7/html/languages/lua/doc/lua51.bnf.html
- Tiny Machine do Kenneth C. Louden - http://www.cs.sjsu.edu/~louden/cmptext/
