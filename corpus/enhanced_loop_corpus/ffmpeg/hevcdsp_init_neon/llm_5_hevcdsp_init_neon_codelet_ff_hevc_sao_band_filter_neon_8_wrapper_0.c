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
    for (k = 0; k < 4; k++) {
        int index = (k + sao_left_class) & 31;
        if (k != 2) {
            offset_table[index] = sao_offset_val[k + 1];
        } else {
            offset_table[index] = 0;
        }
    }
}
