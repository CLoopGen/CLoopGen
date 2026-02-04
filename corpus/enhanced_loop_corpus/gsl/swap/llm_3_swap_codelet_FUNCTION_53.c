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
    // Variant 2: Memory Access Pattern Modification - Indirect Access via Index Array
    // We create an index array that reshapes the access order, simulating indirect memory access.
    volatile int *data_array = (volatile int*)malloc(K * sizeof(int));
    size_t *index_map = (size_t*)malloc(K * sizeof(size_t));
    if (!data_array || !index_map) {
        free((void*)data_array);
        free(index_map);
        return;
    }

    // Initialize index map to reverse order for indirect access pattern
    for (size_t idx = 0; idx < K; idx++) {
        index_map[idx] = K - 1 - idx;
    }

    for (i = 0; i < K; i++) {
        for (j = i + 1; j < K; j++) {
            size_t mapped_index = index_map[j];  // Indirect indexing
            data_array[mapped_index] += mapped_index;
        }
    }

    free((void*)data_array);
    free(index_map);
}
