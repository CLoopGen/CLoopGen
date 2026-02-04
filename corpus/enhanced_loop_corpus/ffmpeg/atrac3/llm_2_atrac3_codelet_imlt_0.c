#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2, processing pairs symmetrically
    for (i = 0; i < 128; i += 2) {
        int idx1 = i;
        int idx2 = 255 - i;
        float SWAP_tmp1 = input[idx2];
        float SWAP_tmp2 = input[254 - i]; // For i+1 mirrored index

        input[idx2] = input[idx1];
        input[254 - i] = input[i + 1];
        input[idx1] = SWAP_tmp1;
        input[i + 1] = SWAP_tmp2;
    }
}
