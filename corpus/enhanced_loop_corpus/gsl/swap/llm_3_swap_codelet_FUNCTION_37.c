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
    // Variant 2: Strided memory access pattern with indirect indexing via pointer arithmetic
    ptrdiff_t stride = 4; // Access every 4th element to simulate strided access
    size_t limit = size1 * size2;
    volatile char *base = (volatile char *)malloc(limit * sizeof(char));
    if (!base) return;

    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2; j += stride) { // Strided iteration in inner loop
            // Perform access with stride on simulated data
            base[(i * size2 + j) * stride % limit] += 1; // Strided write access
        }
    }

    free((void*)base);
}
