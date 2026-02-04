#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern double d;
extern double x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access pattern using a simulated buffer to accumulate values
    // Introduce a small local buffer to process multiple iterations consecutively
    double buffer[4];
    int unroll_factor = 4;
    int limit = n - unroll_factor;

    // Unrolled loop with consecutive updates stored temporarily in buffer
    for (j = 1; j <= limit; j += unroll_factor) {
        buffer[0] = 2 * j          / (2. * x - d);
        buffer[1] = 2 * (j + 1)    / (2. * x - buffer[0]);
        buffer[2] = 2 * (j + 2)    / (2. * x - buffer[1]);
        d = buffer[3] = 2 * (j + 3) / (2. * x - buffer[2]); // Final value written back to d
    }

    // Handle remaining iterations
    for (; j < n; j++) {
        d = 2 * j / (2. * x - d);
    }
}
