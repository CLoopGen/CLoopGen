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
    // Variant 2: Strided memory access pattern - traverse columns first, then rows (column-major like)
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Simulated access with stride: e.g., accessing A[i][j] in row-major storage creates strided access
        }
    }
}
