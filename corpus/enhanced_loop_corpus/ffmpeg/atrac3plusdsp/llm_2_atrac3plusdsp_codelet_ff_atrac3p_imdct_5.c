#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pIn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2
    // This processes only even indices, effectively halving the number of iterations
    // but still covering the first half of the relevant range in strides.
    for (i = 0; i < 128 / 4; i += 2) {
        float SWAP_tmp = pIn[128 - 1 - i];
        pIn[128 - 1 - i] = pIn[i];
        pIn[i] = SWAP_tmp;
    }
}
