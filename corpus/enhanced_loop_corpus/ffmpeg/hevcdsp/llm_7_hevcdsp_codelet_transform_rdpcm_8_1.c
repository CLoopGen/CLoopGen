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
    int16_t *base = coeffs;
    for (y = 0; y < size - 1; y++) {
        for (x = 0; x < size; x++) {
            base[y * size + x] += base[(y - 1) * size + x];
        }
    }
}
