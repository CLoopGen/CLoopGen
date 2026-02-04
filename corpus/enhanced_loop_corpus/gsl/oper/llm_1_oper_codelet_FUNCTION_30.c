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
    // Variant 2: Strided memory access pattern, traversing column-wise with explicit stride
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Simulated strided access (e.g., accessing matrix[j + i*N] in practice)
        }
    }
}
