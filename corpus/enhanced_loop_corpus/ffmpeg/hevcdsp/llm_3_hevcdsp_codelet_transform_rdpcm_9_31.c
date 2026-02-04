#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing via index array
    // Introduce an explicit index array to simulate strided/indirect access pattern
    int16_t *temp = coeffs;
    int *indices = (int*)alloca(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        indices[i] = i; // Direct index map, but enables future non-consecutive patterns
    }
    for (y = 0; y < size - 1; y++) {
        for (x = 0; x < size; x++) {
            int idx = indices[x]; // Use indirect indexing (could be randomized or strided)
            temp[idx] += temp[idx - size];
        }
        temp += size;
    }
}
