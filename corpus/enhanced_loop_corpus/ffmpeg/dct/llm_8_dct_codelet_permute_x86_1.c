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
    for (i = 0; i < 32; i++) {
        int index1 = (i & 56) | idct_sse2_row_perm[i & 7];
        int index2 = ((i + 32) & 56) | idct_sse2_row_perm[(i + 32) & 7];
        dst[index1] = src[i];
        dst[index2] = src[i + 32];
    }
}
