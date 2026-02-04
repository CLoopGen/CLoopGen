#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t left_sum[2][8];
extern uint16_t top_sum[2][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D arrays into sequential row-major order
    uint16_t *top_ptr = &top_sum[0][0];
    uint16_t *left_ptr = &left_sum[0][0];
    for (i = 0; i < 8; i++) {
        top_ptr[i] += (top_ptr[i + 8] * 181 + 128) >> 8;
        left_ptr[i] += (left_ptr[i + 8] * 181 + 128) >> 8;
    }
}
