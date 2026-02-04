#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing
    // Access every second element in a strided pattern, then fill in the gaps
    // This creates a non-unit stride access pattern across the array
    int idx;
    // First pass: strided access with step of 2
    for (idx = 0; idx < 64; idx += 2) {
        coeffs[idx] = coeff;
    }
    // Second pass: fill the odd indices, maintaining strided pattern
    for (idx = 1; idx < 64; idx += 2) {
        coeffs[idx] = coeff;
    }
}
