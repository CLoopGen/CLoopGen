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
    int local_max = max_code_length;
    for (sym = 0; sym < alphabet_size; sym++) {
        local_max = (local_max < code_lengths[sym]) ? code_lengths[sym] : local_max;
    }
    max_code_length = local_max;
}
