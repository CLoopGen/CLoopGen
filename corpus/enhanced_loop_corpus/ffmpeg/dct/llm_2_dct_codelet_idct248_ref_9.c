#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern double block1[64];
extern double s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access via loop interchange and reindexing
    // We reverse the loop order to access memory sequentially in the inner loop
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 4; i++) {
            int base_idx = 8 * (2 * i) + j;
            int offset_idx = base_idx + 8; // 8*(2*i+1)+j = base_idx + 8
            block1[base_idx] = (block[base_idx] + block[offset_idx]) * s;
            block1[offset_idx] = (block[base_idx] - block[offset_idx]) * s;
        }
    }
}
