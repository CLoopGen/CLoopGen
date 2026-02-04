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
    ptrdiff_t stride = (size2 > 4) ? 4 : 1; // Assume strided access every 4 elements, if possible
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            // Strided access: skip elements based on stride
            size_t index = i * size2 + j; // Potential array index usage in real scenario
        }
    }
}
