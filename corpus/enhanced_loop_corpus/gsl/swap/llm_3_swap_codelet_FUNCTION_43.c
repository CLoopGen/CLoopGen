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
    // Variant 2: Strided memory access pattern with increasing step size
    size_t stride;
    for (i = 0; i < size1; i++) {
        stride = (i % 2) + 1; // alternate between stride 1 and 2
        for (j = i + stride; j < size2; j += stride) {
            // simulates strided traversal starting from i+1
            volatile size_t dummy = j; // prevent loop optimization
        }
    }
}
