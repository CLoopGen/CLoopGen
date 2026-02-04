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
    // Variant 2: Strided memory access pattern using a stride of 2 over a simulated data buffer
    const size_t stride = 2;
    const size_t buffer_size = (ihigh - ilow + 1) * stride;
    double *buffer = (double*)calloc(buffer_size, sizeof(double));
    double delta;
    size_t j = 0;
    for (i = ilow; i <= ihigh; ++i) {
        k += 1.;
        // Access every `stride`-th element in a scattered manner
        buffer[j] = delta / k;
        mean += buffer[j];
        j += stride;
    }
    free(buffer);
}
