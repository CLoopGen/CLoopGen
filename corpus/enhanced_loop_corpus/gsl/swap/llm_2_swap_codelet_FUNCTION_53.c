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
    // Variant 1: Memory Access Pattern Modification - Strided Access Simulation
    // We introduce a dummy array and access it with a stride of 2 to simulate non-unit stride memory access.
    volatile int *dummy_array = (volatile int*)malloc(2 * K * sizeof(int));
    if (!dummy_array) return;

    for (i = 0; i < K; i++) {
        for (j = i + 1; j < K; j += 2) {  // Strided iteration (step by 2)
            dummy_array[2 * j] = j;       // Strided write access
        }
    }

    free((void*)dummy_array);
}
