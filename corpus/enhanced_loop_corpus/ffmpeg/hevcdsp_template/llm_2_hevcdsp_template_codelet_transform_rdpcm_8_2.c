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
    // Variant 1: Consecutive memory access with reversed inner loop traversal
    for (y = 0; y < size; y++) {
        for (int i = size - 1; i >= 1; i--) {
            coeffs[i] += coeffs[i - 1];
        }
        coeffs += size;
    }
}
