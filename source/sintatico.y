%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../source/symbol_table.h"
#include "../source/code_generator.h"

int yylex(void);
void yyerror(const char* s);

bool in_print_call;
bool in_local_definition;

int semantic_erros;

int current_line_number;

unsigned int current_scope_level;

extern FILE* yyin;
extern FILE* yyout;

// Variaveis pendentes são variáveis que estão esperando uma atribuição
typedef struct pending_variable {
    char* name;
    struct pending_variable* next;
} pending_variable;

pending_variable* first_pending_var = NULL;

void add_pending_variable(char* name) {
    pending_variable* new_pending_var = (pending_variable*) malloc(sizeof(pending_variable));
    new_pending_var->name = name;

    if (first_pending_var == NULL) {
        first_pending_var = new_pending_var;
    } else {
        pending_variable* current_var = first_pending_var;

        while (current_var->next) {
            current_var = current_var->next;
        }

        current_var->next = new_pending_var;
    }
}

// Gera uma atribuição para a primeira variável pendente
void gen_assignment_for_pending_var() {
    gen_assignment(search_variable(first_pending_var->name, current_scope_level));
    
    pending_variable* next_var = first_pending_var->next;
    free(first_pending_var);
    first_pending_var = next_var;
}

void enter_scope() {
    current_scope_level++;
}

void exit_scope() {
    delete_variables_in_scope(current_scope_level);
    current_scope_level--;
}

%}

%union {
    int ival;
    char* sval;
}

%locations
%define parse.error verbose

%token ATRIBUICAO VIRGULA PONTO_VIRGULA PARENTESE_ESQUERDO PARENTESE_DIREITO RETICENCIAS
%token NIL FALSO VERDADEIRO LOCAL IF THEN ELSE ELSEIF DO END WHILE REPEAT UNTIL FOR FUNCTION RETURN
%token <ival> NUMERO
%token <sval> IDENTIFICADOR

%left MENOR_QUE MAIOR_QUE IGUALDADE
%left AND OR
%left MAIS MENOS
%left MULTIPLICACAO DIVISAO 
%left NOT

// O valor do 'if' é o número de ramos
%type <ival> comando_condicional
%type <ival> lista_elseif

// O valor da 'chamada_funcao' é o nome da função
%type <sval> chamada_funcao

// O valor da 'varivel' é o nome da variável
%type <sval> variavel

%%
programa: 
    lista_comandos 
    { 
        printf("\nPrograma sintaticamente CORRETO!\n"); 

        if (semantic_erros != 0) {
            printf("\nPrograma semanticamente INCORRETO! (%d erros)\n\n", semantic_erros); 
        } else {
            printf("\nPrograma semanticamente CORRETO!\n\n"); 
            gen_object_code(yyout); 
        }
    }
    ;

lista_comandos:
    comando
    | comando PONTO_VIRGULA
    | comando lista_comandos
    | comando PONTO_VIRGULA lista_comandos
    | comando retorno
    | comando lista_comandos retorno
    | comando PONTO_VIRGULA lista_comandos retorno
    ;

comando:
    lista_atribuicao
    | LOCAL { in_local_definition = true; } definicao_variavel { in_local_definition = false; } 
    | bloco_escopo
    | WHILE { add_label(); } expressao { add_label(); skip_code_position(2); } bloco_escopo { gen_while(); }
    | REPEAT { add_label(); enter_scope(); } lista_comandos { exit_scope(); } UNTIL expressao { gen_repeat(); }
    | comando_condicional END { gen_if_end_jump($1); }
    | chamada_funcao
    | FOR { in_local_definition = true; enter_scope(); } variavel ATRIBUICAO expressao VIRGULA
    { 
        gen_assignment_for_pending_var(); 
        in_local_definition = false; 
    } 
    expressao VIRGULA expressao { add_label(); } bloco_escopo 
    { 
        gen_for(search_variable($3, current_scope_level)); 
        exit_scope(); 
    }
    | FUNCTION IDENTIFICADOR corpo_funcao
    | LOCAL FUNCTION IDENTIFICADOR corpo_funcao
    ;

variavel:
    IDENTIFICADOR
    { 
        insert_variable($1, in_local_definition ? current_scope_level : 0, current_line_number++); 
        add_pending_variable($1);
        $$ = $1;
    }

definicao_variavel:
    lista_atribuicao
    | lista_variaveis

lista_atribuicao:
    variavel ATRIBUICAO expressao                           { gen_assignment_for_pending_var(); }
    | variavel VIRGULA lista_atribuicao VIRGULA expressao   { gen_assignment_for_pending_var(); }
    ;

lista_variaveis:
    variavel                                { gen_num(0); gen_assignment_for_pending_var(); /* A variavel recebe 0 */ }
    | variavel VIRGULA lista_variaveis      { gen_num(0); gen_assignment_for_pending_var(); /* A variavel recebe 0 */ }

bloco_escopo:
    DO { enter_scope(); } lista_comandos END { exit_scope(); }

comando_condicional:
    comando_if                                                            { $$ = 1; gen_if_exp_jump(); }
    | comando_if ELSE { gen_if_exp_jump(); } lista_comandos               { $$ = 1; }
    | comando_if lista_elseif                                             { $$ = 1 + $2; gen_if_exp_jump(); }
    | comando_if lista_elseif ELSE { gen_if_exp_jump(); } lista_comandos  { $$ = 1 + $2; }

comando_if:
    IF expressao {  add_label(); skip_code_position(2); enter_scope(); } 
        THEN lista_comandos { exit_scope(); add_label(); skip_code_position(1); }

comando_elseif:
    ELSEIF { gen_if_exp_jump(); } expressao { add_label(); skip_code_position(2); enter_scope(); } 
        THEN lista_comandos { exit_scope(); add_label(); skip_code_position(1); }

lista_elseif:
    comando_elseif lista_elseif       { $$ = 1 + $2; }
    | comando_elseif                  { $$ = 1; }
    ;

lista_parametros:
    lista_variaveis
    | lista_variaveis VIRGULA RETICENCIAS
    | RETICENCIAS
    ;

lista_expressoes:
    expressao                                   { if (in_print_call) gen_print(); }
    | expressao VIRGULA lista_expressoes        { if (in_print_call) gen_print(); }
    ;

expressao: 
    IDENTIFICADOR
    { 
        variable* var = search_variable($1, current_scope_level);

        if (var == NULL) {
            printf(
                "\n*** ERRO SEMÂNTICO | Linha %d: Variável '%s' não foi declarada nesse escopo!\n", 
                current_line_number, $1
            );
            semantic_erros++;
        } else {
            var->is_used = true;

            gen_variable_value(var);
        }
    }
    | NUMERO                                    { gen_num($1); }
    | FALSO                                     { gen_num(0); }
    | VERDADEIRO                                { gen_num(1); }
    | NIL                                       { gen_num(0); }
    | expressao MULTIPLICACAO expressao         { gen_binary_operation(OP_MUL); }
    | expressao DIVISAO expressao               { gen_binary_operation(OP_DIV); }
    | expressao MAIS expressao                  { gen_binary_operation(OP_ADD); }
    | expressao MENOS expressao                 { gen_binary_operation(OP_SUB); }
    | expressao AND expressao                   { gen_binary_operation(OP_AND); }
    | expressao OR expressao                    { gen_binary_operation(OP_OR); }
    | expressao MENOR_QUE expressao             { gen_binary_operation(OP_LESS_THAN); }
    | expressao MAIOR_QUE expressao             { gen_binary_operation(OP_GREATER_THAN); }
    | expressao IGUALDADE expressao             { gen_binary_operation(OP_EQUALITY); }
    | MENOS expressao                           { gen_unary_operation(OP_NEG); }
    | NOT expressao                             { gen_unary_operation(OP_NOT); }
    | chamada_funcao                            { if (strcmp($1, "read") != 0) gen_num(0); }
    | PARENTESE_ESQUERDO expressao PARENTESE_DIREITO
    ;

chamada_funcao:
    IDENTIFICADOR
    {
        if (strcmp($1, "print") == 0) {
            in_print_call = true; 
        } else if (strcmp($1, "read") == 0) {
            gen_read();
        }
    }
    argumentos 
    {
        if (strcmp($1, "print") == 0) {
            in_print_call = false; 
        }

        $$ = strdup($1);
    }
    ;

argumentos:
    PARENTESE_ESQUERDO PARENTESE_DIREITO
    | PARENTESE_ESQUERDO lista_expressoes PARENTESE_DIREITO
    ;

corpo_funcao:
    PARENTESE_ESQUERDO PARENTESE_DIREITO lista_comandos END
    | PARENTESE_ESQUERDO lista_parametros PARENTESE_DIREITO lista_comandos END
    | PARENTESE_ESQUERDO PARENTESE_DIREITO retorno END
    | PARENTESE_ESQUERDO lista_parametros PARENTESE_DIREITO retorno END
    ;

retorno:
    RETURN
    | RETURN lista_expressoes
    ;
%%

int main(int argc, char* argv[]) {
    if (argc > 1) {
        yyin = (FILE *) fopen(argv[1], "r");

        if (yyin == NULL) {
            printf("\nArquivo de entrada inválido!\n\n");
            return 0;
        }
    } else {
        printf("\nPara usar o compilador execute: \"./compilador ./<seu_programa>.lua ./<seu_arquivo_objeto>.tm\"\n\n");
        return 0;
    }

    if (argc > 2) {
	    yyout = (FILE *) fopen(argv[2], "w");
    } else {
        yyout = stdout;
    }

    yyparse();

    verify_not_used_variables();

    fclose(yyin);
    fclose(yyout);
}
