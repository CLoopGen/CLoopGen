#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int shift;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride of 2 (access every other element in each pass)
    int16_t *base = coeffs;
    int total_elements = size * size;
    int stride = 2;
    int offset;

    // First pass: even indices
    for (offset = 0; offset < stride; offset++) {
        for (x = 0; x < total_elements; x += stride) {
            int16_t *current = base + x + offset;
            if (x + offset < total_elements) {
                *current = ((uint16_t)*current) << (-shift);
            }
        }
    }
    // Update global coeffs to point past last modified element
    coeffs += total_elements;
}
