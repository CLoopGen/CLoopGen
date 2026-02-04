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
for (y = 0; y < size && x < size; y++) { // Decreased nesting depth by merging inner loop condition
    *coeffs = *(uint16_t *)coeffs << -shift;
    coeffs++;
    x++;
    if (x >= size) {
        x = 0;
    }
}
}
