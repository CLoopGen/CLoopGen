#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int shift;
extern int x;
extern int y;
extern int size;
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 2nd element in row-major order, then handle remainder
    int total_elements = size * size;
    int stride = 2;
    int16_t *base = coeffs;

    // First pass: strided access
    for (int i = 0; i < total_elements; i += stride) {
        base[i] = (base[i] + offset) >> shift;
    }

    // Second pass: handle any odd-indexed elements if total_elements is not divisible by stride
    for (int i = 1; i < total_elements; i += stride) {
        base[i] = (base[i] + offset) >> shift;
    }
}
