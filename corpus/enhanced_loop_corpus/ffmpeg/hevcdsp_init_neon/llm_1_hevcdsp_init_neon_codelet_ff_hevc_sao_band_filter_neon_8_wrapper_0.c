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
for (k = 0; k < 2; k++) {
    for (int inner = 0; inner < 2; inner++) {
        int idx = k * 2 + inner;
        offset_table[(idx + sao_left_class) & 31] = sao_offset_val[idx + 1];
    }
}
}
