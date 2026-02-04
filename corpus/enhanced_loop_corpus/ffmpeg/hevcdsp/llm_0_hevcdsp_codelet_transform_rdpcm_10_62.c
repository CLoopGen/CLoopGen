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
for (y = 0; y < size; y++) {
    coeffs[y * size + 0] = coeffs[y * size + 0]; // dummy assignment to maintain base address effect
    for (x = 1; x < size; x++) {
        coeffs[y * size + x] += coeffs[y * size + x - 1];
    }
}
}
