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
for (y = 0; y < size * size; y += 2) { // Reduced trip count with stride
    *coeffs = (*coeffs + offset + 1) >> shift; // Simplified single operation
    coeffs++;
    if (y + 1 < size * size) {
        coeffs++; // Skip processing every second element
    }
}
}
