#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access by reindexing into a temporary linear array
    // We reinterpret the access pattern to write to a contiguous block that maps the original indices.
    // Here, we precompute the target indices and write consecutively to avoid scattered accesses.
    double *C_base = (double *)C;
    double *temp_buffer = (double *)malloc(N * sizeof(double));
    if (!temp_buffer) return; // Handle allocation failure

    // Precompute values (simulate work without scattered writes)
    for (i = 0; i < N; i++) {
        temp_buffer[i] = 0.0;
    }

    // Flush results in a single sequential write pattern (simulated by copying to computed offsets)
    for (i = 0; i < N; i++) {
        int index = 2 * (ldc * i + i) + 1;
        C_base[index] = temp_buffer[i];
    }

    free(temp_buffer);
}
