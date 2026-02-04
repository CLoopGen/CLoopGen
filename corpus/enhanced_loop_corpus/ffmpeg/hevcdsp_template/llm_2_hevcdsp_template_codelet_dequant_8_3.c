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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2x
    int16_t* ptr = coeffs;
    int total_elements = size * size;
    for (int i = 0; i < total_elements; i += 2) {
        ptr[0] = (ptr[0] + offset) >> shift;
        if (i + 1 < total_elements) {
            ptr[1] = (ptr[1] + offset) >> shift;
        }
        ptr += 2;
    }
}
