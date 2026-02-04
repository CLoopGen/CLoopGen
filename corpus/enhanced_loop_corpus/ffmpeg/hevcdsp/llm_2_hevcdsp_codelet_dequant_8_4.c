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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    int16_t *ptr = coeffs;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size - 1; x += 2) {
            // Process two elements consecutively to improve spatial locality
            ptr[0] = ((uint16_t)ptr[0]) << (-shift);
            ptr[1] = ((uint16_t)ptr[1]) << (-shift);
            ptr += 2;
        }
        // Handle odd-sized arrays
        if (x < size) {
            *ptr = ((uint16_t)*ptr) << (-shift);
            ptr++;
        }
    }
    coeffs = ptr; // Update global pointer if needed
}
