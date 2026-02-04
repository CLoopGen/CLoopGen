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
    int16_t local_dst[64];
    for (i = 0; i < 64; i++) {
        local_dst[i] = src[i];  // Remove loop-carried dependency by writing to local array first
    }
    for (i = 0; i < 64; i++) {
        dst[idct_simple_mmx_perm[i]] = local_dst[i];  // Final write with permutation, no WAW or RAW across iterations
    }
}
