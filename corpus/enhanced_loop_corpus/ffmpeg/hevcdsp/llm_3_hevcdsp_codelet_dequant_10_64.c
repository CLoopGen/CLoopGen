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
    // Variant 2: Consecutive memory access using pointer arithmetic with precomputed base
    // Flatten the 2D-like indexing into a linear, consecutive pass over memory
    int16_t *base = coeffs;
    for (y = 0; y < size * size; y++) {
        base[y] = ((uint16_t *)(&base[y]))[0] << -shift;
    }
    coeffs += size * size; // Update global pointer to reflect advancement
}
