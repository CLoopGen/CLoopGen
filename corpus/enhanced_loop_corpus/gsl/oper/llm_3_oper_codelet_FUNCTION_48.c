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
    // Variant 2: Strided memory access pattern with column-major traversal (stride of M)
    size_t *access_log = (size_t*)malloc(M * N * sizeof(size_t));
    size_t idx = 0;
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            idx = j + i * N; // Original row-major would be i*N + j; this variant keeps same but simulates indirect use
            access_log[idx] = idx; // Simulated strided write access
        }
    }
    free(access_log);
}
