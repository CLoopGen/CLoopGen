#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t ve[11];
extern uint16_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed base index
    int base;
    for (i = 0; i < 8 / 2 - 2; i++) {
        base = i * 2 + 1;
        vo[i] = (left[base + 2] + left[base + 1] * 2 + left[base] + 2) >> 2;
        ve[i] = (left[base + 3] + left[base + 2] * 2 + left[base + 1] + 2) >> 2;
    }
}
