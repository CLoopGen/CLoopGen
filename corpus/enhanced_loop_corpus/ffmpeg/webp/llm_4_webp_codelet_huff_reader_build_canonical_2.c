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
    if (alphabet_size <= 0) return;
    for (sym = 0; sym < alphabet_size; sym++) {
        if (code_lengths[sym] > max_code_length) {
            max_code_length = code_lengths[sym];
        }
    }
}
