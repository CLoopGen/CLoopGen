#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int val;
extern int max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification using strided access pattern simulation
    // Here we simulate a strided memory access by iterating over a virtual array with stride 2
    // We maintain the same logical behavior: doubling val until it exceeds 16384
    uint32_t *dummy_array = (uint32_t*)calloc(8193, sizeof(uint32_t));
    if (!dummy_array) exit(1);

    for (max_val = 0; val <= 16384; ++max_val) {
        // Simulate strided memory write: every 2nd element
        if (max_val < 8193) {
            dummy_array[2 * max_val] = val;
        }
        val *= 2;
    }

    free(dummy_array);
}
