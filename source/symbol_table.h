#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>
#include <stdlib.h>

#define MAX_MEM_POSITION 1023

/*
OBS: O 'scope level' é o nível do escopo.
Exemplo:

local A = 0;       -> A tem escopo 0
do
    local B = 0;         -> B tem escopo 1
    do 
        local C = 0      -> C tem escopo 2
    end

    D = 0          -> Variáveis globais sempre tem escopo 0
end

Se você está no escopo 2, por exemplo, você só pode acessar variáveis
que foram definidas no escopo 0 ou 1. Você não pode acessar variáveis 
de escopos superiores, como 3, 4, etc.
*/

typedef struct symbol {
    char* name;
    bool is_used;
    bool is_function;
    int loc_code;
    unsigned int memory_position;
    unsigned int scope_level;
    struct symbol* next;
} symbol;

symbol* head_symbol = NULL;

unsigned int next_memory_position;

symbol* search_symbol(char* name, unsigned int scope_level, bool is_function) {
    symbol* current_symbol = head_symbol;

    while (current_symbol) {
        if (current_symbol->is_function == is_function && current_symbol->scope_level <= scope_level && 
                strcmp(current_symbol->name, name) == 0) {
            
            return current_symbol;
        }

        current_symbol = current_symbol->next;
    }

    return NULL;
}

symbol* insert_symbol(char* name, unsigned int scope_level, int loc_code, bool is_function) {
    symbol* existing_symbol = search_symbol(name, scope_level, is_function);

    if (existing_symbol != NULL) {
        return existing_symbol;
    }

    symbol* new_symbol = (symbol*) malloc(sizeof(symbol));
    new_symbol->name = strdup(name);
    new_symbol->scope_level = scope_level;
    new_symbol->loc_code = loc_code;
    new_symbol->is_function = is_function;

    if (!is_function) {
        new_symbol->memory_position = next_memory_position;
    }

    if (next_memory_position++ == MAX_MEM_POSITION) {
        printf("\n*** ERRO | GERAÇÃO DE CÓDIGO: Memória de dados insuficiente.\n\n");
    }
    
    new_symbol->next = head_symbol;
    head_symbol = new_symbol;

    return new_symbol;
}

//podemos adicionar aqui uma checagem de se a variavel foi declarada mas nao usada, dentro do escopo
// mas antes eh necessario entender melhor o codigo...
void delete_symbols_in_scope(unsigned int scope_level) {
    symbol* current_symbol = head_symbol;
    symbol* previous_symbol = NULL;

    while (current_symbol) {
        symbol* next_symbol = current_symbol->next;

        if (current_symbol->scope_level == scope_level) {

            if (previous_symbol == NULL) {
                head_symbol = next_symbol;
            } else {
                previous_symbol->next = next_symbol;
            }

            free(current_symbol);
        }

        current_symbol = next_symbol;
    }
}

void verify_not_used_symbols() {
    symbol* current_symbol;
    for(current_symbol = head_symbol; current_symbol != (symbol *) 0; current_symbol = (symbol *) current_symbol->next){
        if(!current_symbol->is_used) {
            printf(
                "Warning: %s '%s' na linha '%d' foi declarado mas nao utilizado.\n", 
                current_symbol->is_function ? "Função" : "Variável", current_symbol->name, current_symbol->loc_code
            );
        }
    }
}

#endif