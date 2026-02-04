#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access, writing to every 4th element first, then stepping forward
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            coeffs[j * 4 + i] = coeff;  // Access column-major (strided) instead of row-major
        }
    }
}
