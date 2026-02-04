#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern int n;
extern double *out;
extern int i;
extern int j;
extern double *y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity by skipping every other outer iteration
    // This reduces trip count by approximately half while maintaining valid data flow
    for (i = n - 1; i >= 0; i -= 2) {
        // Process only even-indexed iterations in reverse (adjusted logic)
        out[i] = y[i] / matrix[i * n + i];
        for (j = i + 1; j < n; j++) {
            out[i] -= matrix[j * n + i] * out[j];
        }
        // Ensure dependency safety: only update i-1 if it's within bounds
        if (i > 0) {
            out[i-1] = y[i-1] / matrix[(i-1) * n + (i-1)];
            for (j = i; j < n; j++) {
                out[i-1] -= matrix[j * n + (i-1)] * out[j];
            }
        }
    }
}
