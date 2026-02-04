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
    // Variant 1: Strided memory access with positive stride (access every 2nd element)
    int stride = 2;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x += stride) {
            if ((y * size + x / stride) < size) { // Prevent overflow
                int16_t *current = coeffs + (y * size + x);
                *current = (int16_t)((uint16_t)(*current) << -shift);
            }
        }
    }
}
