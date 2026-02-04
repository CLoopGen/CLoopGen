#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int val;
extern int max_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification using indirect (indexed) access
    // Use an index map to access array elements in non-linear order, simulating indirect access
    uint32_t *buffer = (uint32_t*)calloc(14, sizeof(uint32_t));
    uint32_t *indices = (uint32_t*)calloc(14, sizeof(uint32_t));
    if (!buffer || !indices) exit(1);

    // Initialize indirect indices (e.g., reverse order access)
    for (int i = 0; i < 14; ++i) {
        indices[i] = 13 - i;  // reverse mapping
    }

    for (max_val = 0; val <= 16384; ++max_val) {
        // Indirect memory write using remapped index
        if (max_val < 14) {
            buffer[indices[max_val]] = val;
        }
        val *= 2;
    }

    free(buffer);
    free(indices);
}
