#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *sb_samples;
extern float *out_ptr;
extern float *buf;
extern int i;
extern int j;
extern int sblimit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count and simplified inner loop with conditional elimination
    int limit_j = sblimit < 24 ? 24 : 32; // Reduce outer loop iterations
    for (j = sblimit; j < limit_j; j++) {
        out_ptr = sb_samples + j;
        // Unroll inner loop partially (factor of 6) to reduce loop overhead
        for (i = 0; i < 18; i += 6) {
            *out_ptr = buf[4 * i]; out_ptr += 32; buf[4 * i] = 0;
            *out_ptr = buf[4 * (i+1)]; out_ptr += 32; buf[4 * (i+1)] = 0;
            *out_ptr = buf[4 * (i+2)]; out_ptr += 32; buf[4 * (i+2)] = 0;
            *out_ptr = buf[4 * (i+3)]; out_ptr += 32; buf[4 * (i+3)] = 0;
            *out_ptr = buf[4 * (i+4)]; out_ptr += 32; buf[4 * (i+4)] = 0;
            *out_ptr = buf[4 * (i+5)]; out_ptr += 32; buf[4 * (i+5)] = 0;
            out_ptr -= 32 * 6; // Reset out_ptr offset after block write
        }
        out_ptr += 32; // Advance to next sample column
        // Simplify buffer advance: always increment by 1 for predictable stride
        buf += 1;
    }
}
