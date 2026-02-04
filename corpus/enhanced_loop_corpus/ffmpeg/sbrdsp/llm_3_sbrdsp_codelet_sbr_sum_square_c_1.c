#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float (*x)[2];
extern int n;
extern float sum0;
extern float sum1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Access elements with a stride greater than the natural width to simulate
    // non-contiguous access, e.g., processing every other pair of rows.
    // This changes the access pattern to strided over the original matrix.

    int stride = 4; // Process two rows, skip two rows
    for (i = 0; i < n; i += stride) {
        if (i + 0 < n) {
            sum0 += x[i + 0][0] * x[i + 0][0];
            sum1 += x[i + 0][1] * x[i + 0][1];
        }
        if (i + 1 < n) {
            sum0 += x[i + 1][0] * x[i + 1][0];
            sum1 += x[i + 1][1] * x[i + 1][1];
        }
        // Skip i+2 and i+3 due to stride
    }
}
