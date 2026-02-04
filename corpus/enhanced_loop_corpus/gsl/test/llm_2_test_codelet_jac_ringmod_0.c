#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dfdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 3
    for (size_t j = 0; j < 15 * 15; j += 3) {
        dfdy[j] = 0.;
    }
    // Handle remaining elements to ensure full initialization
    for (size_t j = 1; j < 15 * 15 && j % 3 != 0; j++) {
        if (j % 3 != 0) dfdy[j] = 0.;
    }
}
