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

typedef struct variable {
    char* name;
    bool is_used;
    int loc_code;
    unsigned int memory_position;
    unsigned int scope_level;
    struct variable* next;
} variable;

variable* head_var = NULL;

unsigned int next_memory_position;

variable* search_variable(char* name, unsigned int scope_level) {
    variable* current_var = head_var;

    while (current_var) {
        if (current_var->scope_level <= scope_level && strcmp(current_var->name, name) == 0) {
            return current_var;
        }

        current_var = current_var->next;
    }

    return NULL;
}

variable* insert_variable(char* name, unsigned int scope_level, int loc_code) {
    variable* existing_variable = search_variable(name, scope_level);

    if (existing_variable != NULL) {
        return existing_variable;
    }

    variable* new_variable = (variable*) malloc(sizeof(variable));
    new_variable->name = strdup(name);
    new_variable->memory_position = next_memory_position;
    new_variable->scope_level = scope_level;
    new_variable->loc_code = loc_code;

    if (next_memory_position++ == MAX_MEM_POSITION) {
        printf("\n*** ERRO | GERAÇÃO DE CÓDIGO: Memória de dados insuficiente.\n\n");
    }
    
    new_variable->next = head_var;
    head_var = new_variable;

    return new_variable;
}

//podemos adicionar aqui uma checagem de se a variavel foi declarada mas nao usada, dentro do escopo
// mas antes eh necessario entender melhor o codigo...
void delete_variables_in_scope(unsigned int scope_level) {
    variable* current_var = head_var;
    variable* previous_var = NULL;

    while (current_var) {
        variable* next_var = current_var->next;

        if (current_var->scope_level == scope_level) {

            if (previous_var == NULL) {
                head_var = next_var;
            } else {
                previous_var->next = next_var;
            }

            free(current_var);
        }

        current_var = next_var;
    }
}

void verify_not_used_variables() {
    variable* current_var;
    for(current_var = head_var; current_var != (variable *) 0; current_var = (variable *) current_var->next){
        if(!current_var->is_used) {
            printf("Warning: Simbolo '%s' na linha '%d' foi declarado mas nao utilizado.\n", current_var->name, current_var->loc_code);
        }
    }
}

#endif
