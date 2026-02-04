#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ilow;
extern size_t ihigh;
extern double mean;
extern double k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
size_t stride = 4;
for (i = ilow; i <= ihigh; i += stride) {
    double delta;
    // Unroll-like effect with fixed stride memory access pattern
    for (size_t j = 0; j < stride && (i + j) <= ihigh; ++j) {
        k += 1.;
        delta = (double)((i + j) * j); // Simulate access to j-th offset in a vectorized/strided manner
        mean += delta / k;
    }
}
}
