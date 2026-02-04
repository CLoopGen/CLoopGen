#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride simulation
    // Instead of accessing left[i], left[i+1], left[i+2], we pre-offset the pointer to create consecutive pattern
    uint16_t *left_offset = left + 1;
    uint16_t *top_offset = top + 1;
    for (i = 0; i < 8 - 2; i++) {
        v[i] = (left_offset[i-1] + left_offset[i] * 2 + left_offset[i+1] + 2) >> 2;
        v[8 + 1 + i] = (top_offset[i-1] + top_offset[i] * 2 + top_offset[i+1] + 2) >> 2;
    }
}
