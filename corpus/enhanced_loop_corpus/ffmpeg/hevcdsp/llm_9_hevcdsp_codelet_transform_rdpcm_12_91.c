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
            int16_t temp1 = coeffs[x - size];
            int16_t temp2 = coeffs[x - size + 1];
            coeffs[x] += temp1;
            if (x + 1 < size) {
                coeffs[x + 1] += temp2;
            }
        }
        coeffs += size * 2;
        y++; // Simulate larger step in outer loop
    }
}
