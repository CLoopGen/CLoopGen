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
    // Variant 2: Strided memory access - process every 'stride' element first, then next offset
    int stride = 4; // Simulate cache-friendly strided traversal
    int total_elements = size * size;
    int remainder = total_elements % stride;

    // Process elements in strided groups
    for (int s = 0; s < stride; s++) {
        for (int i = s; i < total_elements; i += stride) {
            int16_t* elem = coeffs + i;
            *elem = (*elem + offset) >> shift;
        }
    }
}
