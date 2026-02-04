#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset base pointer
    uint8_t *top_offset = top + 1;
    for (i = 0; i < 8 - 1; i++) {
        ve[4 + i] = (top_offset[i - 1] + top_offset[i] + 1) >> 1;
        vo[4 + i] = (top_offset[i - 2] + top_offset[i - 1] * 2 + top_offset[i] + 2) >> 2;
    }
}
