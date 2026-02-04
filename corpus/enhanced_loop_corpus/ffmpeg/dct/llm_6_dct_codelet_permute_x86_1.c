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
    int temp_dst[64];
    for (i = 0; i < 64; i++) {
        temp_dst[(i & 56) | idct_sse2_row_perm[i & 7]] = src[i];
    }
    for (i = 0; i < 64; i++) {
        dst[i] = temp_dst[i];
    }
}
