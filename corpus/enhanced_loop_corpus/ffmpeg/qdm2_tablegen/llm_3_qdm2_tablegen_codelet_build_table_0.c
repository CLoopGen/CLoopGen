#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int table_size;
extern int i;
extern volatile int16_t (*volatile table)[2];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    // Simulate indirect access via a precomputed index permutation (within bounds)
    int *indices = (int*)malloc(table_size * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Create a simple indirect access order: reverse order
    for (int j = 0; j < table_size; j++) {
        indices[j] = table_size - 1 - j;
    }

    for (int j = 0; j < table_size; j++) {
        int idx = indices[j]; // Indirect access through index array
        if (idx < table_size && table[idx][1] == 0) {
            table[idx][0] = -1;
        }
    }

    free(indices);
}
