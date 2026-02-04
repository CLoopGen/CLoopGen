#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Simulate strided access by stepping through indices with a fixed stride
    // Assuming hypothetical array 'data' with row-major layout, access every 4th element
    const size_t stride = 4;
    for (i = 0; i < size1; i += stride) {
        for (j = 0; j < size2; j++) {
            // Simulated access: would typically involve data[i * size2 + j]
            // Stride applied on outer loop to create non-consecutive access
        }
    }
}
