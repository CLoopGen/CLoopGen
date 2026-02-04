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
    for (i = 0; i < 64; i += 8) {
        for (int j = 0; j < 8; j++) {
            dst[(i & 56) | idct_sse2_row_perm[j]] = src[i | j];
        }
    }
}
