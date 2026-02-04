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
        for (x = 0; x < size; x += 2) {
            *coeffs = (*coeffs + offset + 1) >> shift;
            coeffs++;
            if (x + 1 < size) {
                *coeffs = (*coeffs + offset - 1) >> shift;
                coeffs++;
            }
        }
    }
}
