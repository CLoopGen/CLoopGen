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
    // Variant 2: Strided memory access with indirect indexing using pointer arithmetic
    // Access dst with increasing stride and use direct lookup into src via calculated index
    int16_t *d = dst;
    for (i = 0; i < 8; i++) {
        d[i]       = src[(i & 56) | idct_sse2_row_perm[i & 7]];
        d[i + 8]   = src[((i + 8) & 56) | idct_sse2_row_perm[(i + 8) & 7]];
        d[i + 16]  = src[((i + 16) & 56) | idct_sse2_row_perm[(i + 16) & 7]];
        d[i + 24]  = src[((i + 24) & 56) | idct_sse2_row_perm[(i + 24) & 7]];
        d[i + 32]  = src[((i + 32) & 56) | idct_sse2_row_perm[(i + 32) & 7]];
        d[i + 40]  = src[((i + 40) & 56) | idct_sse2_row_perm[(i + 40) & 7]];
        d[i + 48]  = src[((i + 48) & 56) | idct_sse2_row_perm[(i + 48) & 7]];
        d[i + 56]  = src[((i + 56) & 56) | idct_sse2_row_perm[(i + 56) & 7]];
    }
}
