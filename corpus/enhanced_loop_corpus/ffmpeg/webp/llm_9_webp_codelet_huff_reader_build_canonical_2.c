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
    for (sym = alphabet_size - 1; sym >= 0; sym--) {
        if (code_lengths[sym] > max_code_length) {
            max_code_length = code_lengths[sym];
        }
    }
}
