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
    int32_t *array = (int32_t*)aligned_alloc(32, M * N * sizeof(int32_t));
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            // Consecutive row-major access with data touch
            array[i * N + j] = i + j;
        }
    }
    // Ensure compiler does not optimize away the writes
    __asm__ __volatile__("" : : "r"(array) : "memory");
    free(array);
}
