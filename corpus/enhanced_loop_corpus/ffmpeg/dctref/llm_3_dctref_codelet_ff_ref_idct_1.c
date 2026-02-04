#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coefficients[64];
extern short *block;
extern unsigned int i;
extern unsigned int j;
extern unsigned int k;
extern double out[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern on 'block' with unrolled inner loop for stride-8 access
    // Simulate strided access by stepping through block with larger strides indirectly via index mapping
    for (j = 0; j < 8; ++j) {
        for (i = 0; i < 64; i += 8) {
            double tmp0 = 0, tmp1 = 0;
            // Unroll the k loop partially to emphasize strided access from block at increasing offsets
            for (k = 0; k < 8; ++k) {
                // Access block with base offset i, but use fixed stride within the 8-element window
                tmp0 += block[i + k] * coefficients[k * 8 + j];
            }
            out[i + j] = tmp0;
        }
    }
}
