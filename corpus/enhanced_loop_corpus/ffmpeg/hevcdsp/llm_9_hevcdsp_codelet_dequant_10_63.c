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
    for (y = 0; y < size * size; y++) {
        int temp = (y % (size / 2)) + offset;
        coeffs[y] = (coeffs[y] + temp) >> (shift + (y & 1));
    }
}
