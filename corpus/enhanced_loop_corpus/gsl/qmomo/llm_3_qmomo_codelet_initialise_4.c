#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *rj;
extern double *rh;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    size_t indices[12];
    for (size_t j = 0; j < 12; ++j) {
        indices[j] = 1 + 2*j; // Store original odd indices: 1, 3, 5, ..., 23
    }
    for (size_t j = 0; j < 12; ++j) {
        size_t idx = indices[j];
        rj[idx] *= -1;
        rh[idx] *= -1;
    }
}
