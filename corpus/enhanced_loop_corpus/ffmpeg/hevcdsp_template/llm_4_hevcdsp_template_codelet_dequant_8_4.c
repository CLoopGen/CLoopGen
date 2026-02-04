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
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            if (shift > 0) {
                *coeffs = *(uint16_t *)coeffs >> shift;
            } else {
                *coeffs = *(uint16_t *)coeffs << (-shift);
            }
            coeffs++;
        }
    }
}
