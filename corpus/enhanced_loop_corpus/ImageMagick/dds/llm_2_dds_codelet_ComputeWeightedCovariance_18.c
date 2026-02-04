#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *covariance;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, then wrap with offset)
    // This accesses every second element in two passes to cover all indices
    for (size_t j = 0; j < 2; j++) {
        for (size_t i = j; i < 6; i += 2) {
            covariance[i] = 0.F;
        }
    }
}
