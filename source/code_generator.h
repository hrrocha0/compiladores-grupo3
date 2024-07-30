#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <stdio.h>

int current_code_position;

void gen_print_constant(FILE* object_file, int constant) {
    fprintf(
        object_file, 
        "%d:  LDC 0,%d(0)       * Reg[0] = %d\n"
        "%d:  OUT 0,0,0         * Reg[0] -> saída padrão\n", 
        current_code_position, constant, constant,
        current_code_position + 1
    );

    current_code_position += 2;
}

void gen_halt(FILE* object_file) {
    fprintf(
        object_file, 
        "%d:  HALT 0,0,0\n",
        current_code_position++
    );
}

#endif