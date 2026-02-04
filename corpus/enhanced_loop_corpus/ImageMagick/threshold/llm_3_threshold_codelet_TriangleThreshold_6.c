#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated with computed indices)
    // Precomputed indirect access pattern: reverse traversal order using an index mapping
    ssize_t mapped_index;
    for (i = 0; i <= (ssize_t)255; i++) {
        // Reverse access: from 255 down to 0, but still using forward loop counter
        mapped_index = (ssize_t)255 - i;
        if (histogram[mapped_index] > 0.) {
            start = mapped_index;
            break;
        }
    }
}
