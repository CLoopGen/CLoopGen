#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using index array
    // Use an explicitly defined index map to simulate indirect addressing
    int *indices = (int*)malloc(size * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Initialize index array to identity mapping
    for (int i = 0; i < size; i++) {
        indices[i] = i;
    }

    for (y = 0; y < size - 1; y++) {
        for (x = 0; x < size; x++) {
            int idx = indices[x]; // Indirect access via index table
            if (idx - size >= 0) {
                coeffs[idx] += coeffs[idx - size];
            }
        }
        coeffs += size;
    }

    free(indices);
}
