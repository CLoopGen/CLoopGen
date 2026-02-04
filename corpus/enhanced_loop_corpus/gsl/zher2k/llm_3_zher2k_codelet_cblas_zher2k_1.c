#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2, separating real and imaginary parts (assuming complex data)
    double *C_ptr = (double *)C;
    int total_elements = 2 * ldc * N;
    // First initialize even indices (e.g., real parts) in a strided manner
    for (i = 0; i < total_elements; i += 2) {
        C_ptr[i] = 0.;
    }
    // Then initialize odd indices (e.g., imaginary parts)
    for (i = 1; i < total_elements; i += 2) {
        C_ptr[i] = 0.;
    }
    // Note: This variant assumes the entire matrix up to size N x N is zeroed,
    // but uses a flattened, strided traversal instead of row-wise triangular access.
    // It maintains correctness under the assumption that only lower triangular part is used later.
}
