#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out[32];
extern uint8_t *in;
extern int i;
extern int plane_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling by 4
    uint8_t *base = in;
    for (i = 0; i < 32; i += 4) {
        out[i]     = base + i * plane_size;
        if (i + 1 < 32) out[i + 1] = base + (i + 1) * plane_size;
        if (i + 2 < 32) out[i + 2] = base + (i + 2) * plane_size;
        if (i + 3 < 32) out[i + 3] = base + (i + 3) * plane_size;
    }
}
