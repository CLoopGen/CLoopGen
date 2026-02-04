#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base offset
    // Instead of strided writes to v[i*2] and v[i*2+1], write consecutively using a pointer
    uint16_t *dest = v;
    for (i = 0; i < 8 - 2; i++) {
        *dest++ = (left[i] + left[i + 1] + 1) >> 1;
        *dest++ = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
    }
}
