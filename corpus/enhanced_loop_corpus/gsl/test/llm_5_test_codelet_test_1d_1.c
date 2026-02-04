#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t N;
extern size_t stride;
extern size_t i;
extern double *data;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = stride; i < N * stride; i++) {
        size_t prev = i - stride;
        if (prev > 0) {
            status |= (data[prev] != (12345. + prev));
        }
    }
    // Handle remaining elements not aligned to stride
    for (; i < N * stride + stride - 1 && i < N * stride; i++) {
        if (i % stride != 0) {
            status |= (data[i] != (12345. + i));
        }
    }
}
