#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array to reverse the first 128 elements
    int indices[128];
    for (i = 0; i < 128; i++) {
        indices[i] = 255 - i;  // Precompute reversed indices
    }

    for (i = 0; i < 128; i++) {
        int j = indices[i];  // Indirect access via lookup
        float SWAP_tmp = input[j];
        input[j] = input[i];
        input[i] = SWAP_tmp;
    }
}
