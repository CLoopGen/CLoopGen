#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *sao_offset_val;
extern int sao_left_class;
extern int16_t offset_table[32];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t prev_val = 0;
    for (k = 0; k < 4; k++) {
        int16_t current_val = sao_offset_val[k + 1] + prev_val;
        offset_table[(k + sao_left_class) & 31] = current_val;
        prev_val = current_val;
    }
}
