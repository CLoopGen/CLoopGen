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
    // Variant 2: Strided memory access - process every 2nd element first, then the odd positions
    int16_t *ptr = coeffs;
    int total_elements = size * size;
    int stride = 2;
    int phase, i;

    for (phase = 0; phase < stride; phase++) {
        for (i = phase; i < total_elements; i += stride) {
            ptr[i] = (ptr[i] + offset) >> shift;
        }
    }
    // Update global coeffs to point past last written element
    coeffs = ptr + total_elements;
}
