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
for (i = 1; i < M; i++) {
    // Rearranged loop order to enable consecutive memory access pattern
    // Assuming data access depends on 'j' as primary dimension, now iterating in row-major like fashion
    size_t upper = ((i) < (N) ? (i) : (N));
    for (j = 0; j < upper; j += 1) {
        // Simulate consecutive access: e.g., accessing A[j] sequentially
        // This improves spatial locality compared to non-linear or out-of-order access
        volatile size_t dummy = j;
        (void)dummy;
    }
}
}
