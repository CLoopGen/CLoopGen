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
    // Variant 1: Consecutive memory access by reordering loops to improve spatial locality
    // We swap the j and k loops and accumulate into a temporary array to enable consecutive coefficient access
    double temp[64] = {0};
    for (i = 0; i < 64; i += 8) {
        for (k = 0; k < 8; ++k) {
            double b_val = block[i + k];
            for (j = 0; j < 8; ++j) {
                temp[i + j] += b_val * coefficients[k * 8 + j];
            }
        }
    }
    // Copy results to out
    for (i = 0; i < 64; ++i) {
        out[i] = temp[i];
    }
}
