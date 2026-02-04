#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Process array in strided manner with step size 8, unrolling to maintain total 64 iterations
    for (i = 0; i < 8; i++) {
        dst[i]           = src[(i << 3) | 0];
        dst[i + 8]       = src[(i << 3) | 1];
        dst[i + 16]      = src[(i << 3) | 2];
        dst[i + 24]      = src[(i << 3) | 3];
        dst[i + 32]      = src[(i << 3) | 4];
        dst[i + 40]      = src[(i << 3) | 5];
        dst[i + 48]      = src[(i << 3) | 6];
        dst[i + 56]      = src[(i << 3) | 7];
    }
}
