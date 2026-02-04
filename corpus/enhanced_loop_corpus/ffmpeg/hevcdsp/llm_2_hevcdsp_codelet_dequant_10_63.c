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
    // Variant 1: Consecutive memory access using pointer arithmetic with pre-computed bounds
    int16_t *start = coeffs;
    int16_t *end = coeffs + size * size;
    for (int i = 0; start < end; i++) {
        *start = (*start + offset) >> shift;
        start++;
    }
}
