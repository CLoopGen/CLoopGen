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
    max_code_length = 0;
    for (sym = 0; sym < alphabet_size; ++sym) {
        int cl = code_lengths[sym];
        if (cl == 0) continue;
        if (cl > max_code_length) {
            max_code_length = cl;
        }
    }
}
