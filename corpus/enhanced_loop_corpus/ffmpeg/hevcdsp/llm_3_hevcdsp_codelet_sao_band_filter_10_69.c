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
    // Variant 2: Strided memory access with increased stride in destination
    int stride = 8; // Stride of 8 for demonstration (keeps within 32-entry table)
    for (k = 0; k < 4; k++) {
        int dest_index = (k * stride + sao_left_class) & 31;
        offset_table[dest_index] = sao_offset_val[k + 1];
    }
}
