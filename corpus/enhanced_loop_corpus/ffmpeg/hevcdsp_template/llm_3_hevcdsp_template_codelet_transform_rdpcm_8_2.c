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
    // Variant 2: Strided memory access — process every second element in two passes
    for (y = 0; y < size; y++) {
        // First pass: odd indices
        for (x = 2; x < size; x += 2) {
            coeffs[x] += coeffs[x - 1];
        }
        // Second pass: even indices
        for (x = 1; x < size; x += 2) {
            if (x > 0) {
                coeffs[x] += coeffs[x - 1];
            }
        }
        coeffs += size;
    }
}
