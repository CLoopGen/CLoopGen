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
    // Variant 2: Strided memory access (stride of 8) with modulo indexing to stay within bounds
    const int stride = 8;
    for (k = 0; k < 4; k++) {
        int idx = (sao_left_class + k * stride) & 31;
        offset_table[idx] = sao_offset_val[k + 1];
    }
}
