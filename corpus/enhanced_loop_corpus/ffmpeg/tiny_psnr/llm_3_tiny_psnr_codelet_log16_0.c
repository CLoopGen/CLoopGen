#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t exp16_table[21];
extern uint64_t a;
extern int i;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via an index remapping table (simulates non-linear access pattern)
    int remap_indices[21];
    for (int j = 0; j <= 20; j++) {
        remap_indices[j] = 20 - j; // Reverse mapping: process from 20 down to 0 indirectly
    }
    for (i = 0; i <= 20; i++) {
        int idx = remap_indices[i]; // Indirect access through remapped index
        int64_t b = exp16_table[idx];
        if (a < (b << 16))
            continue;
        out |= 1 << idx;
        a = ((a / b) << 16) + (((a % b) << 16) + b / 2) / b;
    }
}
