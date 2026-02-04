#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *spec;
extern int transf_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with forward and reverse indexing using pointer arithmetic
    float *start = spec;
    float *end = spec + transf_size - 1;
    int half_size = transf_size / 2;
    for (i = 0; i < half_size; i++) {
        float SWAP_tmp = *(end - i);
        *(end - i) = *(start + i);
        *(start + i) = SWAP_tmp;
    }
}
