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
for (y = 0; y < size; y++) {
    for (x = 0; x < size; x++) {
        int16_t val = *coeffs;
        val = (val + offset) >> shift;
        val = (val * val) + offset; // Increased arithmetic intensity
        *coeffs = val & 0xFFFF;     // Clamp to 16-bit
        coeffs++;
    }
}
}
