#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access via Pointer Arithmetic
    // We restructure the loop to use pointer arithmetic and process elements consecutively
    // within each row segment starting at C[ldc * i + i] to improve spatial locality.
    // The inner loop now operates on a base pointer incremented sequentially.

    for (i = 0; i < N; i++) {
        double *base_C = &C[ldc * i + i];  // Start at diagonal element
        int length = N - i;
        for (int k = 0; k < length; k++) {
            base_C[k] *= beta;  // Consecutive access
        }
    }
}
