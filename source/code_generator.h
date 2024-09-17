#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>

/*
    O 'stack_pointer' é usado para gerenciar as variáveis temporárias e a geração de código. 
    Tome a expressão '2 + 3', por exemplo:
        * Quando o compilador encontrar o número '2' vai empilhar esse valor na pilha:
            [1023] = 2
        * De modo similar, quando encontrar o número '3' vai empilhar esse valor na pilha:
            [1023] = 2  
            [1022] = 3
        * Ao encontrar o token '+' os dois últimos valores da pilha serão retirados, e o resultado
        da operação será empilhado no topo da pilha
            [1023] = 5
*/
unsigned int stack_pointer = 1023;

typedef enum BINARY_OPERATION { 
    OP_ADD,
    OP_SUB, 
    OP_MUL, 
    OP_DIV, 
    OP_AND, 
    OP_OR,
    OP_LESS_THAN,
    OP_GREATER_THAN,
    OP_EQUALITY
} BINARY_OPERATION;

typedef enum UNARY_OPERATION {
    OP_NEG,
    OP_NOT
} UNARY_OPERATION;


typedef struct code_chunk {
    char* code;
    struct code_chunk* next;
} code_chunk;

code_chunk* head_chunk = NULL;

typedef struct function_code {
    char* function_name;
    struct code_chunk* head_code_chunk;
    struct function_code* previous;
} function_code;

function_code* last_function_code = NULL;


typedef struct code_position {
    unsigned int code_postion;
    struct code_position* previous;
} code_position;

code_position* last_saved_code_position = NULL;


unsigned int current_code_position;

void save_code_position() {
    code_position* new_code_position = (code_position*) malloc(sizeof(code_position));
    new_code_position->code_postion = current_code_position;
    
    new_code_position->previous = last_saved_code_position;
    last_saved_code_position = new_code_position;
}

void skip_code_position(int count) {
    current_code_position += count;
}

// Reverte 'current_code_position' para a ultima posição salva
void revert_code_position() {
    current_code_position = last_saved_code_position->code_postion;

    code_position* temp = last_saved_code_position;
    last_saved_code_position = last_saved_code_position->previous;
    free(temp);
}

char* function_definition_name;

function_code* get_function_code(char* function_name) {
    function_code* function = last_function_code;

    while (function) {
        if (strcmp(function->function_name, function_name) == 0) {
            return function;
        }
        function = function->previous;
    }

    return NULL;
}

void add_code_chunk_to_function(char* function_name, code_chunk* function_code_chunk) {
    function_code* function = get_function_code(function_name);

    if (function == NULL) {
        function = (function_code*) malloc(sizeof(function_code));
        function->function_name = strdup(function_name);
        function->previous = last_function_code;
        last_function_code = function;
    }

    if (function->head_code_chunk == NULL) {
        function->head_code_chunk = function_code_chunk;
    } else {
        code_chunk* current_code_chunk = function->head_code_chunk;

        while (current_code_chunk->next) {
            current_code_chunk = current_code_chunk->next;
        }

        current_code_chunk->next = function_code_chunk;
    }
}

void clear_function_code(char* function_name) {
    function_code* function = get_function_code(function_name);

    if (function == NULL) return;

    code_chunk* current_code_chunk = function->head_code_chunk;
    code_chunk* previous_code_chunk = NULL;

    function->head_code_chunk = NULL;

    while (current_code_chunk)
    {
        previous_code_chunk = current_code_chunk;
        current_code_chunk = current_code_chunk->next;
        free(previous_code_chunk);
    }
}

void add_code_chunk(char* code) {
    code_chunk* new_chunk = (code_chunk*) malloc(sizeof(code_chunk));
    new_chunk->code = strdup(code);

    if (function_definition_name != NULL) {
        add_code_chunk_to_function(function_definition_name, new_chunk);
        return;
    }
    
    if (head_chunk == NULL) {
        head_chunk = new_chunk;
    } else {
        code_chunk* current_chunk = head_chunk;

        while (current_chunk) {
            if (current_chunk->next == NULL) {
                current_chunk->next = new_chunk;
                break;
            }

            current_chunk = current_chunk->next;
        }
    }
}

void gen_RO(char* instruction, int r, int s, int t, char* comment) {
    char chunk[80];

    if (function_definition_name != NULL) {
        // Se estivermos gerando código para uma função, não é para adicionar 
        // o code_position, isso será feito depois

        sprintf(
            chunk,"  %s %d,%d,%d       %s\n", 
            instruction, r, s, t, comment == NULL ? "" : comment
        );
        current_code_position++;
    } else {
        sprintf(
            chunk,"%d:  %s %d,%d,%d       %s\n", 
            current_code_position++, instruction, r, s, t, comment == NULL ? "" : comment
        );
    }

    add_code_chunk(chunk);
}

void gen_RM(char* instruction, int r, int d, int s, char* comment) {
    char chunk[80];

    if (function_definition_name != NULL) {
        // Se estivermos gerando código para uma função, não é para adicionar 
        // o code_position, isso será feito depois

        sprintf(
            chunk,"  %s %d,%d(%d)       %s\n", 
            instruction, r, d, s, comment == NULL ? "" : comment
        );
        current_code_position++;
    } else {
        sprintf(
            chunk, "%d:  %s %d,%d(%d)       %s\n", 
            current_code_position++, instruction, r, d, s, comment == NULL ? "" : comment
        );
    }

    add_code_chunk(chunk);
}

void gen_object_code(FILE* object_file) {
    gen_RO("HALT", 0, 0, 0, NULL);

    code_chunk* current_chunk = head_chunk;

    while (current_chunk)
    {
        fputs(current_chunk->code, object_file);
        current_chunk = current_chunk->next;
    }
}

void gen_print() {
    stack_pointer++;

    char comment[50];
    sprintf(comment, "* dMem[%d] -> saída padrão", stack_pointer);

    gen_RM("LD", 0, stack_pointer, 5, NULL);    // Carrega no Reg(0) o valor a ser impresso
    gen_RO("OUT", 0, 0, 0, comment);            // Envia o valor para a saída padrão
}

void gen_read() {
    char comment[50];
    sprintf(comment, "* dMem[%d] <- entrada padrão", stack_pointer);

    gen_RO("IN", 0, 0, 0, NULL);                    // Lê valor da entrada padrão
    gen_RM("ST", 0, stack_pointer, 5, comment);     // Armazena o valor na pilha

    stack_pointer--;
}

void gen_num(int num) {
    char comment[50];
    sprintf(comment, "* dMem[%d] = %d", stack_pointer, num);

    gen_RM("LDC", 0, num, 0, NULL);                 // Carrega o número no Reg(0) 
    gen_RM("ST", 0, stack_pointer, 5, comment);     // Armazena o valor na pilha

    stack_pointer--;
}

void gen_variable_value(symbol* var) {
    char comment[50];
    sprintf(comment, "* dMem[%d] = '%s'", stack_pointer, var->name);

    gen_RM("LD", 0, var->memory_position, 5, NULL);     // Carrega o valor da variável no Reg(0) 
    gen_RM("ST", 0, stack_pointer, 5, comment);         // Armazena o valor na pilha

    stack_pointer--;
}

void gen_assignment(symbol* var) {
    stack_pointer++; 

    char comment[50];
    sprintf(comment, "* '%s' = dMem[%d]", var->name, stack_pointer);

    gen_RM("LD", 0, stack_pointer, 5, NULL);                // Carrega no Reg(0) o valor que está no topo da pilha
    gen_RM("ST", 0, var->memory_position, 5, comment);      // Armazena o valor no endereço da variável
}

/*
    Gera as instruções de salto para o comando 'while'. Exemplo:

    1: while (exp) do <- Gera um salto do final do 'while' (3) para cá
    2:    ...
    3:    ...
    4: end
    5: ... <- Gera um salto para cá caso 'exp' for falsa
*/
void gen_while() {
    code_position* while_expression_position = last_saved_code_position->previous;
    code_position* while_body_position = last_saved_code_position;

    // Gera um salto incondicional para a expressão do while
    gen_RM("LDA", 7, while_expression_position->code_postion - current_code_position, 7, NULL);

    unsigned int while_end_code_position = current_code_position;
    current_code_position = while_body_position->code_postion;

    // Verifica se a condição do 'while' é falsa (valor igual a zero). Se sim, salta para o fim do loop
    gen_RM("LD", 0, stack_pointer + 1, 5, NULL);
    gen_RM("JEQ", 0, while_end_code_position - current_code_position - 1, 7, NULL);

    current_code_position = while_end_code_position;
    stack_pointer++;

    last_saved_code_position = while_expression_position->previous;
    free(while_expression_position);
    free(while_body_position);
}

/*
    Gera a instrução de salto para o comando 'repeat'. Exemplo:

    1: repeat <- Gera um salto para cá se 'exp' for falsa
    2:    ...
    3:    ...
    4: until (exp)
*/
void gen_repeat() {
    code_position* repeat_expression_position = last_saved_code_position;

    stack_pointer++;

    // Verifica se a condição do 'repeat' é falsa (valor igual a zero). Se sim, volta para o começo do loop
    gen_RM("LD", 0, stack_pointer, 5, NULL);
    gen_RM("JEQ", 0, repeat_expression_position->code_postion - current_code_position - 1, 7, NULL);

    last_saved_code_position = repeat_expression_position->previous;
    free(repeat_expression_position);
}

/*
    Gera a instrução de salto para o caso do 'if' ser falso. Exemplo:

    1: if (exp) then 
    2:    ...
    3: end  <- Gera um salto para cá se 'exp' for falsa
*/
void gen_if_exp_jump() {
    code_position* if_expression_position = last_saved_code_position->previous;

    stack_pointer++;

    unsigned int if_end_code_position = current_code_position;
    current_code_position = if_expression_position->code_postion;

    // Se a condição for do if for falsa (valor igual a zero), salta para o fim do bloco if
    gen_RM("LD", 0, stack_pointer, 5, NULL);
    gen_RM("JEQ", 0, if_end_code_position - current_code_position - 1, 7, NULL);

    current_code_position = if_end_code_position;

    last_saved_code_position->previous = if_expression_position->previous;
    free(if_expression_position);
}

/*
    Gera as instruções de salto para fora do bloco 'if'. Exemplo:

    1: if (exp) then 
    2:    ...
    3: elseif (exp) then
    4:    ...
    5: else
    6:    ...
    7: end -> Gera um jump de (2), (4) e (6) para cá

    Onde 'num_of_branches' é o número de ramos que devem ser analisados, e, consequentemente,
    o número de jumps que devem ser gerados
*/
void gen_if_end_jump(int num_of_branches) {
    for (int i = 0; i < num_of_branches; i++)
    {
        code_position* branch_end_position = last_saved_code_position;

        unsigned int if_end_code_position = current_code_position;
        current_code_position = branch_end_position->code_postion;

        // Gera um salto incondicional para fora do bloco do 'if'
        gen_RM("LDA", 7, if_end_code_position - current_code_position - 1, 7, NULL);

        current_code_position = if_end_code_position;

        last_saved_code_position = branch_end_position->previous;
        free(branch_end_position);
    }
}

void gen_for(symbol* counter_variable) {
    code_position* for_body_position = last_saved_code_position;

    stack_pointer++;

    // Incrementa o valor da variável contador
    gen_RM("LD", 0, stack_pointer, 5, NULL);
    gen_RM("LD", 1, counter_variable->memory_position, 5, NULL);
    gen_RO("ADD", 0, 0, 1, NULL);

    // Armazena o novo valor do contador na memória da variável
    gen_RM("ST", 0, counter_variable->memory_position, 5, NULL);

    stack_pointer++;

    // Avalia se, de acordo com o valor do contador e a condição do loop, o loop deve continuar
    gen_RM("LD", 1, stack_pointer, 5, NULL);
    gen_RO("SUB", 0, 1, 0, NULL);
    gen_RM("JGT", 1, 2, 7, NULL);
    gen_RM("JLE", 0, for_body_position->code_postion - current_code_position - 1, 7, NULL);
    gen_RM("LDA", 7, 1, 7, NULL);
    gen_RM("JGE", 0, for_body_position->code_postion - current_code_position - 1, 7, NULL);

    last_saved_code_position = for_body_position->previous;
    free(for_body_position);
}

void gen_function_code(char* function_name) {
    function_code* function = get_function_code(function_name);

    if (function == NULL) return;

    code_chunk* current_code_chunk = function->head_code_chunk;

    while (current_code_chunk)
    {
        char chunk[80];

        if (function_definition_name != NULL) {
            // Se estivermos gerando código para uma função, não é para adicionar 
            // o code_position, isso será feito depois
            sprintf(chunk, "%s", current_code_chunk->code);
        } else {
            sprintf(
                chunk, "%d:  %s", 
                current_code_position++, current_code_chunk->code
            );
        }

        add_code_chunk(chunk);

        current_code_chunk = current_code_chunk->next;
    }
}

void gen_binary_operation(BINARY_OPERATION opcode) {
    if (opcode == OP_AND || opcode == OP_OR) {
        char comment[80];
        sprintf(
            comment, "* dMem[%d] = dMem[%d] %s dMem[%d]", 
            stack_pointer + 2, stack_pointer + 1, opcode == OP_AND ? "AND" : "OR", stack_pointer + 2
        );

        // Carrega os operandos da pilha no Reg(0) e Reg(1)
        gen_RM("LD", 0, stack_pointer + 1, 5, NULL);
        gen_RM("LD", 1, stack_pointer + 2, 5, NULL);

        // Verifica se os operados são falsos ou verdadeiros, e armazena no Reg(0) o resultado
        // da operação lógica em questão
        gen_RM(opcode == OP_AND ? "JEQ" : "JNE", 0, 3, 7, NULL);
        gen_RM(opcode == OP_AND ? "JEQ" : "JNE", 1, 2, 7, NULL);
        gen_RM("LDC", 0, opcode == OP_AND ? 1 : 0, 0, NULL);
        gen_RM("LDA", 7, 1, 7, NULL);
        gen_RM("LDC", 0, opcode == OP_AND ? 0 : 1, 0, NULL);

        // Armazena o resultado na pilha
        gen_RM("ST", 0, stack_pointer + 2, 5, comment);

        stack_pointer++;
        return;
    }

    if (opcode == OP_LESS_THAN || opcode == OP_GREATER_THAN || opcode == OP_EQUALITY) {
        char comment[80];
        sprintf(
            comment, "* dMem[%d] = dMem[%d] %s dMem[%d]", 
            stack_pointer + 2, stack_pointer + 2, 
            opcode == OP_EQUALITY ? "==" : opcode == OP_LESS_THAN ? "<" : ">",
            stack_pointer + 1
        );

        // Carrega os operandos da pilha no Reg(0) e Reg(1)
        gen_RM("LD", 0, stack_pointer + 2, 5, NULL);
        gen_RM("LD", 1, stack_pointer + 1, 5, NULL);

        // Realiza a comparação
        gen_RO("SUB", 0, 0, 1, NULL);
        gen_RM(opcode == OP_EQUALITY ? "JEQ" : opcode == OP_LESS_THAN ? "JLT" : "JGT", 0, 2, 7, NULL);

        // Armazena o resultado da comparação na pilha (0 = falso, 1 = verdadeiro)
        gen_RM("LDC", 0, 0, 0, NULL);
        gen_RM("LDA", 7, 1, 7, NULL);
        gen_RM("LDC", 0, 1, 0, NULL);
        gen_RM("ST", 0, stack_pointer + 2, 5, comment);

        stack_pointer++;
        return;
    }

    char* operation;

    switch (opcode) {
        case OP_ADD:
            operation = "ADD";
            break;
        case OP_SUB:
            operation = "SUB";
            break;
        case OP_MUL:
            operation = "MUL";
            break;
        case OP_DIV:
            operation = "DIV";
            break;
    }

    char comment[80];
    sprintf(
        comment, "* dMem[%d] = dMem[%d] %s dMem[%d]", 
        stack_pointer + 2, stack_pointer + 2, operation, stack_pointer + 1
    );

    gen_RM("LD", 0, stack_pointer + 2, 5, NULL);        // Carrega os operandos da pilha
    gen_RM("LD", 1, stack_pointer + 1, 5, NULL);
    gen_RO(operation, 0, 0, 1, NULL);                   // Realiza a operação
    gen_RM("ST", 0, stack_pointer + 2, 5, comment);     // Armazena o resultado na pilha

    stack_pointer++;
}

void gen_unary_operation(UNARY_OPERATION opcode) {
    if (opcode == OP_NEG) {
        char comment[50];
        sprintf(comment, "* dMem[%d] = - dMem[%d]", stack_pointer + 1, stack_pointer + 1);

        gen_RM("LDC", 0, 0, 0, NULL);
        gen_RM("LD", 1, stack_pointer + 1, 5, NULL);        // Carrega o operando da pilha no Reg(0)
        gen_RO("SUB", 0, 0, 1, NULL);                       // Reg(0) = 0 - Reg(0), ou seja, o seu valor negado
        gen_RM("ST", 0, stack_pointer + 1, 5, comment);     // Armazena o resultado na pilha

    } else if (opcode == OP_NOT) {
        char comment[50];
        sprintf(comment, "* dMem[%d] = not dMem[%d]", stack_pointer + 1, stack_pointer + 1);

        gen_RM("LD", 0, stack_pointer + 1, 5, NULL);        // Carrega o operando da pilha no Reg(0)
        gen_RM("JNE", 0, 2, 7, NULL);                      
        gen_RM("LDC", 0, 1, 0, NULL);                       // Reg(0) == 0 ? Reg(0) = 1
        gen_RM("LDA", 7, 1, 7, NULL);
        gen_RM("LDC", 0, 0, 0, NULL);                       // Reg(0) != 0 ? Reg(0) = 0
        gen_RM("ST", 0, stack_pointer + 1, 5, comment);     // Armazena o resultado na pilha
    }
}

#endif