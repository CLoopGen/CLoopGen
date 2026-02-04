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
    // Variant 2: Strided memory access - process every 'stride' element in a row-major layout
    const int stride = 2; // Access every second element
    int total_elements = size * size;
    int idx;
    for (idx = 0; idx < total_elements; idx += stride) {
        int16_t *current = coeffs + idx;
        *current = (*current + offset) >> shift;
    }
    // Final cleanup pass for remaining elements if needed
    for (idx = total_elements - (total_elements % stride); idx < total_elements; idx++) {
        int16_t *current = coeffs + idx;
        *current = (*current + offset) >> shift;
    }
}
