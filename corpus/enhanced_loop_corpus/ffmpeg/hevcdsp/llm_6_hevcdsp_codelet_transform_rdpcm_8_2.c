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
for (y = 0; y < size; y++) {
    for (x = 1; x < size; x++)
        coeffs[x] = coeffs[x] + coeffs[x - 1] + 1;
    coeffs += size;
}
}
