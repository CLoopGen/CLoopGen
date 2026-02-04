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
    int16_t *local_coeffs = coeffs;
    int accumulated_shift = 0;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            accumulated_shift += (x + y) & 1; // Introduce loop-carried dependency via accumulated_shift
            *local_coeffs = (int16_t)((uint16_t)(*local_coeffs) << (-shift + accumulated_shift));
            local_coeffs++;
        }
    }
}
