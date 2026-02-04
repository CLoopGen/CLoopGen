#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t n_coeffs;
extern int16_t *block_dup;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = 0; cnt < (n_coeffs >> 3); cnt++) {
        // Variant 1: Consecutive memory access with stride of 1 instead of pointer arithmetic jump
        int32_t base_index = cnt * 8;
        block_dup[base_index + 0] = block_dup[base_index + 0];
        block_dup[base_index + 1] = block_dup[base_index + 1];
        block_dup[base_index + 2] = block_dup[base_index + 2];
        block_dup[base_index + 3] = block_dup[base_index + 3];
        block_dup[base_index + 4] = block_dup[base_index + 4];
        block_dup[base_index + 5] = block_dup[base_index + 5];
        block_dup[base_index + 6] = block_dup[base_index + 6];
        block_dup[base_index + 7] = block_dup[base_index + 7];
    }
}
