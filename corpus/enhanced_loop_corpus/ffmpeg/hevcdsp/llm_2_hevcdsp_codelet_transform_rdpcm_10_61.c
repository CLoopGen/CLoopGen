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
    // Variant 1: Strided memory access pattern
    // Instead of accessing consecutive elements in inner loop, use a stride of 2 (unrolling effect)
    // Handle even and odd indices separately to maintain correctness with strided access
    for (y = 0; y < size - 1; y++) {
        for (x = 0; x < size; x += 2) {
            if (x + 1 < size) {
                coeffs[x]     += coeffs[x - size];
                coeffs[x + 1] += coeffs[x + 1 - size];
            } else {
                coeffs[x] += coeffs[x - size];
            }
        }
        coeffs += size;
    }
}
