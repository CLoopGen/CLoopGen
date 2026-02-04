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
    // Variant 2: Strided memory access pattern, traversing column-major with stride of M
    size_t *access_order = (size_t*)malloc(M * N * sizeof(size_t));
    if (!access_order) return;
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            access_order[j * M + i] = i * N + j; // Simulate strided access: transpose-like indexing
        }
    }
    free(access_order);
}
