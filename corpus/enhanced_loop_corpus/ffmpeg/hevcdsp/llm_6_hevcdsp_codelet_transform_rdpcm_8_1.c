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
    for (y = 1; y < size; y++) {
        for (x = 0; x < size; x++) {
            int16_t temp = coeffs[x - size];
            coeffs[x] += temp;
        }
        coeffs += size;
    }
}
