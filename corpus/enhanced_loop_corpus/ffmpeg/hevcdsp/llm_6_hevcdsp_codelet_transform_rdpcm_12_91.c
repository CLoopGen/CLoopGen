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
    for (y = 0; y < size - 1; y++) {
        int16_t temp = 0;
        for (x = 0; x < size; x++) {
            temp = coeffs[x - size];
            coeffs[x] += temp;
        }
        coeffs += size;
    }
}
