#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the coefficient access pattern
    // Instead of accessing `coeffs[x - size]`, we precompute a base pointer and use consecutive indexing
    int16_t *base = coeffs;
    for (y = 0; y < size - 1; y++) {
        int16_t *current_row = base + y * size;
        int16_t *prev_row = current_row - size;
        for (x = 0; x < size; x++) {
            current_row[x] += prev_row[x];
        }
    }
}
