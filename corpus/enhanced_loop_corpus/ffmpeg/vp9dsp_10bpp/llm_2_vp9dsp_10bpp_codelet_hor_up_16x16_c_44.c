#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride-2 pattern
    // Instead of writing to v[i*2] and v[i*2+1], write consecutively to v[2*i] and v[2*i+1]
    // This maintains logical equivalence but improves spatial locality in writes.
    for (i = 0; i < 16 - 2; i++) {
        int base = 2 * i;
        uint16_t l_i = left[i];
        uint16_t l_i1 = left[i + 1];
        uint16_t l_i2 = left[i + 2];
        v[base]     = (l_i + l_i1 + 1) >> 1;
        v[base + 1] = (l_i + (l_i1 << 1) + l_i2 + 2) >> 2;
    }
}
