#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with increased stride in the inner loop
    ptrdiff_t stride = 2; // Stride factor for accessing 'virtual' array elements
    for (i = 0; i < M; i += (i & 1) ? 1 : 2) {  // Modify outer loop step based on condition to vary access
        for (j = i + stride; j < N; j += stride) {
            // Simulate strided access, e.g., touching every 'stride'-th element
            volatile size_t accessed_index = (i + j) * stride;
            // Prevent unused variable warning
            (void)accessed_index;
        }
    }
}
