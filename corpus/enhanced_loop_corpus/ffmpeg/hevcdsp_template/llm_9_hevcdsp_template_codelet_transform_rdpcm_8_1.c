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
    for (y = 0; y < size - 2; y += 2) {
        for (x = 0; x < size; x += 2) {
            coeffs[x] += coeffs[x - size];
            if (x + 1 < size) {
                coeffs[x + 1] += coeffs[x + 1 - size];
            }
        }
        coeffs += 2 * size;
    }
}
