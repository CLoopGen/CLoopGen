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
    for (y = 0; y < size && shift > 0; y++) {
        for (x = 0; x < size; x++) {
            int16_t temp = *coeffs + offset;
            if (temp > 0) {
                *coeffs = temp >> shift;
            } else {
                *coeffs = (temp + (1 << shift) - 1) >> shift;
            }
            coeffs++;
        }
    }
}
