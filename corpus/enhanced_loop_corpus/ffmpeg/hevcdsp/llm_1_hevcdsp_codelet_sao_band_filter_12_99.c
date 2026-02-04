#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *sao_offset_val;
extern int sao_left_class;
extern int offset_table[32];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 2; k++) {
        offset_table[(k + sao_left_class) & 31] = sao_offset_val[k + 1];
        offset_table[((k + 2) + sao_left_class) & 31] = sao_offset_val[k + 3];
    }
}
