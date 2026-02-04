#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *data = (uint64_t*)malloc(M * sizeof(uint64_t));
    if (!data) return;

    for (i = 0; i < M; i++) {
        data[i] = i * N; // Write to data[i] – WAW possible if reordered
        for (j = 0; j < N; j++) {
            data[i] += j; // RAW: read-modify-write on data[i]; loop-carried dependence within outer loop iteration
        }
    }

    // Eliminate loop-carried dependencies between iterations of i via reduction-like update
    for (i = 1; i < M; i++) {
        data[i] += data[i-1]; // Now introduces loop-carried flow (RAW) dependency across outer loop iterations
    }
    free(data);
}
