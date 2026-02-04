#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sb_samples;
extern int *out_ptr;
extern int *buf;
extern int i;
extern int j;
extern int sblimit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access via out_ptr += 32, we rewrite the inner loop to write consecutive outputs.
    // We precompute the target indices in sb_samples and access buf with a fixed offset pattern.
    int *base_out;
    for (j = sblimit; j < 32; j++) {
        base_out = sb_samples + j;
        int stride = (j & 3) != 3 ? 1 : (4 * 18 - 3);
        for (i = 0; i < 18; i++) {
            int idx = 4 * i;
            base_out[i * 32] = buf[idx];
            buf[idx] = 0;
        }
        buf += stride;
    }
}
