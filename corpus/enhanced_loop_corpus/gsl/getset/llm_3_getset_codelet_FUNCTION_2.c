#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t N;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[1024];
    for (size_t i = 0; i < N && i < 1024; i++) {
        indices[i] = rand() % N; // Random indirect indexing
    }
    for (j = 0; j < N && j < 1024; j++) {
        unsigned int k;
        // Indirect memory access via precomputed random indices
        // Simulates irregular access pattern (e.g., arr[indices[j]])
    }
}
