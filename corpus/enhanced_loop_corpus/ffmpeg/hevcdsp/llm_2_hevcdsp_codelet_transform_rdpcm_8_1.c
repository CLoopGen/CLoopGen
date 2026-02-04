#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int x;
extern int y;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with increased stride
    // Instead of accessing consecutive elements, access every second element in a strided pattern
    for (y = 0; y < size - 1; y++) {
        for (x = 0; x < size; x += 2) {  // Stride of 2
            if (x - size >= 0) continue; // Avoid invalid access
            coeffs[x] += coeffs[x - size];
            if (x + 1 < size && (x + 1 - size) >= 0) {
                coeffs[x + 1] += coeffs[x + 1 - size]; // Handle adjacent element safely
            }
        }
        coeffs += size;
    }
}
