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
    // Variant 2: Strided memory access pattern, traversing column-wise with stride M
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Simulating access to a 2D array element A[i][j] with stride M
            size_t index = i + j * M;  // Strided access: step by M
        }
    }
}
