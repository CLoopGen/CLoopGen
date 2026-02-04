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
    for (y = 0; y < size / 2; y++) {
        for (x = 0; x < size; x += 2) {
            int16_t temp1 = coeffs[x];
            int16_t temp2 = coeffs[x + 1];
            coeffs[x] = temp1 - temp2;
            coeffs[x + 1] = temp2 + temp1;
        }
        coeffs += size * 2;
    }
}
