#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_sse2_row_perm[8];
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering the store operations
    // Instead of scattering writes via permutation, we process indices in a way that groups consecutive destinations
    for (i = 0; i < 8; i++) {
        int base = i << 3; // i * 8
        dst[base + 0] = src[(i << 3) | idct_sse2_row_perm[0]];
        dst[base + 1] = src[(i << 3) | idct_sse2_row_perm[1]];
        dst[base + 2] = src[(i << 3) | idct_sse2_row_perm[2]];
        dst[base + 3] = src[(i << 3) | idct_sse2_row_perm[3]];
        dst[base + 4] = src[(i << 3) | idct_sse2_row_perm[4]];
        dst[base + 5] = src[(i << 3) | idct_sse2_row_perm[5]];
        dst[base + 6] = src[(i << 3) | idct_sse2_row_perm[6]];
        dst[base + 7] = src[(i << 3) | idct_sse2_row_perm[7]];
    }
}
