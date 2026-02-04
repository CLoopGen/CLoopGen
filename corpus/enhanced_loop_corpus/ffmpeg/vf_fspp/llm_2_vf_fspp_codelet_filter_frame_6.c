#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  short custom_threshold[64];
extern int i;
extern int bias;
extern int custom_threshold_m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolling the loop to process two elements per iteration
    for (i = 0; i < 64; i += 2) {
        custom_threshold_m[i] = (int)(custom_threshold[i] * (bias / 71.0) + 0.5);
        if (i + 1 < 64) {
            custom_threshold_m[i + 1] = (int)(custom_threshold[i + 1] * (bias / 71.0) + 0.5);
        }
    }
}
