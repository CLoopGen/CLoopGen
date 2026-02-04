#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *spec;
extern int transf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access (stride of 2) to process elements in two interleaved sequences
    int half_size = transf_size / 2;
    int stride = 2;
    // Process even indices first
    for (i = 0; i < half_size; i += stride) {
        int j = i;
        if (j >= half_size) break;
        float SWAP_tmp = spec[transf_size - 1 - j];
        spec[transf_size - 1 - j] = spec[j];
        spec[j] = SWAP_tmp;
    }
    // Process odd indices
    for (i = 1; i < half_size; i += stride) {
        float SWAP_tmp = spec[transf_size - 1 - i];
        spec[transf_size - 1 - i] = spec[i];
        spec[i] = SWAP_tmp;
    }
}
