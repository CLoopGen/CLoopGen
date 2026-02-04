#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int j2max;
extern double power2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write pattern to an array, simulating consecutive memory access
    // Allocate a buffer to hold powers of two in consecutive locations
    double *buffer = (double*)calloc(j2max + 1, sizeof(double));
    if (!buffer) return;

    buffer[1] = power2;
    for (k = 1; k <= j2max; k++) {
        buffer[k] = power2;
        power2 *= 2;
    }

    // Ensure compiler does not optimize away writes
    power2 = buffer[j2max];

    free(buffer);
}
