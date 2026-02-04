#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *code_lengths;
extern int alphabet_size;
extern int sym;
extern int max_code_length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *cl = code_lengths;
    for (sym = 0; sym < alphabet_size; sym += 2) {
        if (sym < alphabet_size) {
            max_code_length = (max_code_length > cl[sym]) ? max_code_length : cl[sym];
        }
        if (sym + 1 < alphabet_size) {
            max_code_length = (max_code_length > cl[sym + 1]) ? max_code_length : cl[sym + 1];
        }
    }
}
