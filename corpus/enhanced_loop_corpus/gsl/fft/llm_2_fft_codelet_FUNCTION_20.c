#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t p_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a dummy array
    size_t *dummy_array = (size_t*)malloc(p_1 * sizeof(size_t));
    for (k1 = 0; k1 < p_1; k1++) {
        dummy_array[k1] = k1; // Sequential write access
    }
    free(dummy_array);
}
