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
    // Create and use an index array to enable indirect memory access pattern.
    size_t* indices = (size_t*)malloc(K * sizeof(size_t));
    if (!indices) return;
    // Initialize index array with shuffled or reordered indices to create indirect access
    for (size_t idx = 0; idx < K; idx++) {
        indices[idx] = (idx * 7) % K; // pseudo-shuffle using linear congruential scheme
    }
    volatile uint8_t dummy = 0;
    for (i = 0; i < K; i++) {
        for (j = i + 1; j < K; j++) {
            // Use indirect indexing: access based on indices[i], indices[j]
            size_t pos_i = indices[i];
            size_t pos_j = indices[j];
            // Simulate data access at indirectly computed locations
            dummy ^= ((uint8_t*)(&K))[(pos_i + pos_j) % sizeof(size_t)];
        }
    }
    free(indices);
}
