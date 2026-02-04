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
    // Variant 2: Strided memory access pattern
    // Traverse columns with a fixed stride, accessing non-consecutive rows per iteration
    // Simulates accessing every 'k'-th element in a flattened matrix column-wise
    const size_t stride = 2;  // Access every second row for same column
    for (j = 0; j < size2; j++) {
        for (i = 0; i < size1; i += stride) {
            // Strided access: skips elements, reduces temporal locality
            // Could model sparse matrix access or subsampling
        }
    }
}
