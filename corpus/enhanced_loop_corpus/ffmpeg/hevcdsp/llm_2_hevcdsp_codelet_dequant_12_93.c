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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    int16_t *ptr = coeffs;
    int total_elements = size * size;
    int i;
    for (i = 0; i < total_elements; i += 2) {
        *ptr = (*ptr + offset) >> shift;
        ptr++;
        if (i + 1 < total_elements) {
            *ptr = (*ptr + offset) >> shift;
            ptr++;
        }
    }
    coeffs = ptr; // Update global coeffs pointer to reflect advancement
}
