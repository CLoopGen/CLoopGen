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
    // Variant 2: Strided memory access pattern, iterating column-wise with stride N
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Simulate strided access (e.g., matrix[j + i*N] if array were present)
        }
    }
}
