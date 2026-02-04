#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_simple_mmx_perm[64];
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < 64; i += 4) {
        dst[idct_simple_mmx_perm[i]] = src[i];
        if (i + 1 < 64) dst[idct_simple_mmx_perm[i+1]] = src[i+1];
        if (i + 2 < 64) dst[idct_simple_mmx_perm[i+2]] = src[i+2];
        if (i + 3 < 64) dst[idct_simple_mmx_perm[i+3]] = src[i+3];
    }
}
