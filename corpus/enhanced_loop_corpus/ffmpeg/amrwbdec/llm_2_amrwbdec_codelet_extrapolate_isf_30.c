#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (unrolling-like pattern)
    // Only process even indices, effectively creating a strided access pattern
    for (i = 2; i < 20 - 16; i += 2) {
        if (diff_isf[i] + diff_isf[i - 2] < 5.) {
            if (diff_isf[i] > diff_isf[i - 2]) {
                diff_isf[i - 2] = 5. - diff_isf[i];
            } else {
                diff_isf[i] = 5. - diff_isf[i - 2];
            }
        }
        // Handle odd index if within bounds (simulate full coverage)
        if (i - 1 >= 1 && diff_isf[i - 1] + diff_isf[i - 2] < 5.) {
            if (diff_isf[i - 1] > diff_isf[i - 2]) {
                diff_isf[i - 2] = 5. - diff_isf[i - 1];
            } else {
                diff_isf[i - 1] = 5. - diff_isf[i - 2];
            }
        }
    }
}
