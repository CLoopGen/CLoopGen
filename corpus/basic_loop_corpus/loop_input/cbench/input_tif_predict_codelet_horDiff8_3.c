#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;
typedef int32 tsize_t;

tsize_t stride;
char *cp;

int i;

static char *buffer;

void init_vars() {
    // Allocate approximately 64MB of data to ensure loop runs about 0.01 seconds
    // This size may vary by CPU, but provides a reasonable workload
    const size_t data_size = 64 * 1024 * 1024;
    buffer = (char*)calloc(data_size + 8, sizeof(char));
    if (!buffer) {
        exit(1);
    }

    // Initialize buffer with non-zero values to avoid potential optimizations
    for (size_t j = 0; j < data_size + 8; j++) {
        buffer[j] = (char)(j & 0xFF);
    }

    // Set stride to a value that allows safe access and ensures loop runs sufficiently
    stride = data_size / 4;  // Ensures many iterations without excessive runtime

    // Ensure cp points within allocated buffer such that cp[stride] and cp[0] are valid
    // during all loop iterations. We decrement cp in the loop, so start near the end.
    cp = buffer + data_size - 4;

    // Adjust stride if necessary to prevent out-of-bounds access
    if (stride > data_size) {
        stride = data_size / 8;
    }

    // Final safety bounds: ensure initial cp[stride] is within buffer
    while ((size_t)(cp - buffer + stride) >= data_size + 8) {
        cp--;
    }

    // Ensure initial condition i = stride - 4 > 0 leads to at least one iteration
    if ((int)(stride - 4) <= 0) {
        stride = 100;
        cp = buffer + 50;
    }
}