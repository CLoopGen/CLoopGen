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
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x += 2) {
            int16_t val1 = *(int16_t *)coeffs;
            *coeffs = val1 << -shift;
            coeffs++;
            if (x + 1 < size) {
                int16_t val2 = *(int16_t *)coeffs;
                *coeffs = val2 << -shift;
                coeffs++;
            }
        }
    }
}
