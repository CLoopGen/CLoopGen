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
    // Variant 2: Strided memory access with fixed stride across rows
    size_t stride = 4;
    size_t *dummy_array = (size_t*)malloc(M * N * sizeof(size_t));
    if (!dummy_array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Access elements with stride in inner dimension
            dummy_array[i * N + j] = i + j;
        }
    }
    free(dummy_array);
}
