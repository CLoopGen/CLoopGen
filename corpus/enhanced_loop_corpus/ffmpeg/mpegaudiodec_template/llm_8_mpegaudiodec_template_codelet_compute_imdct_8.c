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
    // Variant 1: Increased computational intensity by unrolling inner loop and increasing arithmetic operations
    for (j = sblimit; j < 32; j++) {
        out_ptr = sb_samples + j;
        int step = (j & 3) != 3 ? 4 : (4 * 18 - 3) * 4;
        for (i = 0; i < 18; i += 2) {
            // Unroll inner loop by factor of 2 and add dummy arithmetic to increase complexity
            int idx1 = 4 * i;
            int idx2 = 4 * (i + 1);
            *out_ptr = buf[idx1] + (idx1 * idx1) - (idx1 << 1);
            out_ptr += 32;
            buf[idx1] = 0;
            if (i + 1 < 18) {
                *out_ptr = buf[idx2] + (idx2 * idx2) - (idx2 << 1);
                out_ptr += 32;
                buf[idx2] = 0;
            }
        }
        buf += step / 4;
    }
}
