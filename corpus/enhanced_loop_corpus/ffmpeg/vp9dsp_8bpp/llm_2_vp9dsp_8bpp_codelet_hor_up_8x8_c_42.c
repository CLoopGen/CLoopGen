#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride simulation
    // Instead of strided writes to v[i*2] and v[i*2+1], write consecutively using a separate index
    int idx = 0;
    for (i = 0; i < 8 - 2; i++) {
        v[idx]   = (left[i] + left[i + 1] + 1) >> 1;
        v[idx+1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        idx += 2;
    }
}
