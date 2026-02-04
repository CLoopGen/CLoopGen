#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *covariance;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    // Defines a fixed access pattern through an auxiliary index array
    size_t indices[6] = {5, 4, 3, 2, 1, 0}; // Reverse order access
    for (size_t j = 0; j < 6; j++) {
        covariance[indices[j]] = 0.F;
    }
}
