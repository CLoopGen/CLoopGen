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
    int16_t local_src[64];
    for (i = 0; i < 64; i++) {
        local_src[i] = src[i];
    }
    for (i = 0; i < 64; i++) {
        dst[(i & 56) | idct_sse2_row_perm[i & 7]] = local_src[i];
    }
}
