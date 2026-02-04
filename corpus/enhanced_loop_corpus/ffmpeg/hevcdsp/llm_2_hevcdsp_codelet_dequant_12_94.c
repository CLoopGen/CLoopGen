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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    int16_t *ptr = coeffs;
    int total_elements = size * size;
    for (int i = 0; i < total_elements; i += 2) {
        ptr[0] = ((uint16_t)ptr[0]) << (-shift);
        if (i + 1 < total_elements) {
            ptr[1] = ((uint16_t)ptr[1]) << (-shift);
        }
        ptr += 2;
    }
}
