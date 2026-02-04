#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather) memory access using index array
    // Simulate non-contiguous, indirect access via an index lookup table
    volatile char data[1 << 20];
    size_t index_map[512]; // Assume size1 * size2 <= 512 for safety

    // Initialize index map with pseudo-random but valid offsets (for simulation)
    for (size_t idx = 0; idx < 512; idx++) {
        index_map[idx] = (idx * 73) % (1 << 20); // Simple permutation
    }

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            size_t flat_idx = i * size2 + j;
            if (flat_idx < 512) {
                size_t mapped_addr = index_map[flat_idx];
                volatile char temp = data[mapped_addr];
                (void)temp;
            }
        }
    }
}
