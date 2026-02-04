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
    // Variant 2: Indirect memory access via index array
    // Simulate indirect addressing using precomputed indices to access coeffs
    int *indices = (int*)alloca(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        indices[i] = i; // identity mapping for clarity, could be randomized in real scenarios
    }
    for (y = 0; y < size - 1; y++) {
        for (x = 0; x < size; x++) {
            int idx = indices[x]; // indirect access index
            coeffs[idx] += coeffs[idx - size];
        }
        coeffs += size;
    }
}
