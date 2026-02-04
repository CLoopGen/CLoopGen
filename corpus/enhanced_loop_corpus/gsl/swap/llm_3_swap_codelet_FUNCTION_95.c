#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    extern size_t K;
    extern size_t i;
    extern size_t j;
    // Variant 2: Memory Access Pattern Modification - Indirect access via index mapping array
    // Create an index permutation to simulate indirect memory access
    volatile int *data = (volatile int*)malloc(K * sizeof(int));
    size_t *indices = (size_t*)malloc(K * sizeof(size_t));
    for (i = 0; i < K; i++) {
        indices[i] = (i * 7) % K;  // pseudo-random permutation for indirect access
    }
    for (i = 0; i < K; i++) {
        size_t idx_i = indices[i];
        for (j = i + 1; j < K; j++) {
            size_t idx_j = indices[j];
            data[idx_j] += data[idx_i];  // indirect memory access using permuted indices
        }
    }
    free((void*)data);
    free((void*)indices);
}
