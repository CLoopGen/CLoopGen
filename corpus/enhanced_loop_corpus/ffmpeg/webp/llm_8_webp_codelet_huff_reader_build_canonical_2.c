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
    int temp_max = 0;
    for (sym = 0; sym < alphabet_size; sym += 2) {
        if (sym + 1 < alphabet_size) {
            int val1 = code_lengths[sym];
            int val2 = code_lengths[sym + 1];
            temp_max = (temp_max > val1) ? temp_max : val1;
            temp_max = (temp_max > val2) ? temp_max : val2;
        } else {
            temp_max = (temp_max > code_lengths[sym]) ? temp_max : code_lengths[sym];
        }
    }
    max_code_length = temp_max;
}
