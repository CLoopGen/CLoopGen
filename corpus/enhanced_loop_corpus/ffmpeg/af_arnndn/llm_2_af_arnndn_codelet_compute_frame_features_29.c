#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *features;
extern float *ceps_0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle remaining elements
    int i;
    for (i = 0; i < 22; i += 2) {
        ceps_0[i] = features[i];
    }
    // Handle any potential odd-sized leftover (though 22 is even, this maintains correctness)
    for (i = 1; i < 22; i += 2) {
        ceps_0[i] = features[i];
    }
}
