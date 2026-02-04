#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 16 bytes (4 int16_t elements)
    // Simulate accessing columns first by iterating over rows with fixed column offset
    // This creates non-consecutive, strided access pattern across the array.
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            coeffs[j * 4 + i] = coeff;  // Same as coeffs[i + j*4], but emphasizes column-wise traversal
        }
    }
}
