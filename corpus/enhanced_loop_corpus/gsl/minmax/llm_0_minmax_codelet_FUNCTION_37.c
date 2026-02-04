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
    size_t *indices = (size_t*)malloc(N * sizeof(size_t));
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            indices[j] = j * 2; // Strided access pattern: step of 2
        }
        for (j = 0; j < N; j++) {
            if (indices[j] < N) {
                // Simulate strided memory access
                __asm__ __volatile__("" : "+m" (indices[indices[j]]));
            }
        }
    }
    free(indices);
}
