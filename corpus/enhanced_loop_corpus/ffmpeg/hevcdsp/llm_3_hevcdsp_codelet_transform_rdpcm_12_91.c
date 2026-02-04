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
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an index array to access coeffs indirectly, simulating non-sequential access.
    // We create a simple indirect mapping (reversed order within each row) for variation.
    int *indices = (int*)alloca(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        indices[i] = size - 1 - i;  // reverse mapping
    }
    for (y = 0; y < size - 1; y++) {
        for (x = 0; x < size; x++) {
            int idx = indices[x];  // indirect access index
            coeffs[idx] += coeffs[idx - size];
        }
        coeffs += size;
    }
}
