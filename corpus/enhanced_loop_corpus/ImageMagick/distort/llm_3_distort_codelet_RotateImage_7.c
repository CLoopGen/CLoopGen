#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double angle;
extern size_t rotations;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const size_t N = 512;
    double *buffer = (double*)aligned_alloc(32, N * sizeof(double));
    if (!buffer) exit(1);

    for (size_t offset = 0; offset < N; offset++) {
        buffer[offset] = angle - 90. * offset;
    }

    rotations = 0;
    for (size_t step = 0; step < N; step++) {
        if (buffer[step] <= 45.) break;
        rotations = step + 1;
    }

    free(buffer);
}
