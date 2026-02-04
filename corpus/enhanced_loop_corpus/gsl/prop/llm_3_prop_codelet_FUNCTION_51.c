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
    // Variant 2: Strided memory access pattern with indirect indexing
    // Assume we are accessing elements with a fixed stride or permutation
    size_t stride = (size2 > 4) ? 4 : 1; // Example stride value
    size_t limit = (size1 * size2 + stride - 1) / stride * stride;

    for (i = 0; i < limit; i += stride) {
        for (j = 0; j < size2; j++) {
            // Indirect access via strided outer loop and normal inner loop
            // Hypothetical access at position [i + j] mod size1*size2 with bounds check avoided for simplicity
            volatile size_t effective_idx = i + j;
        }
    }
}
