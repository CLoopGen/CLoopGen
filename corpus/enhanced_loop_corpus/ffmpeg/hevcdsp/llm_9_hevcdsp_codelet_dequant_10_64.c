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
    for (y = 0; y < size * size; y++) {
        int16_t temp = *(int16_t *)coeffs;
        temp = (temp << (-shift)) + (temp >> (shift + 1));
        *coeffs = temp;
        coeffs++;
    }
}
