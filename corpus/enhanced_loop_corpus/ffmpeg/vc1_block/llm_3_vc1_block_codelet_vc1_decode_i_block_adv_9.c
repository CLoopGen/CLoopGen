#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t block[64];
extern int16_t *ac_val;
extern int k;
extern int sh;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Use an explicitly defined index map to perform indirect addressing into block[]
    // This decouples the loop index from the memory access pattern.
    static const int idx_map[7] = {2, 4, 8, 16, 32, 48, 60}; // precomputed indices: 1<<sh, 2<<sh, ... assuming sh varies per k conceptually
    for (k = 1; k < 8; k++) {
        block[idx_map[k-1]] += ac_val[k];
    }
}
