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
    // Variant 2: Strided memory access pattern - iterate column-wise with fixed stride
    // Access elements with stride M, simulating non-unit stride access across rows
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Strided access: treat data as if accessing arr[i][j] in column-major fashion
            // This creates a non-consecutive access pattern when M is large
            volatile size_t dummy = i * N + j; // Simulate address calculation
        }
    }
}
