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
    int16_t *local_coeffs = coeffs;
    int combined_shift = shift;
    int acc = 0;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            acc += (*local_coeffs + offset) >> combined_shift;
            *local_coeffs = acc & 0xFFFF; // Introduce WAW and loop-carried dependency
            local_coeffs++;
        }
    }
}
