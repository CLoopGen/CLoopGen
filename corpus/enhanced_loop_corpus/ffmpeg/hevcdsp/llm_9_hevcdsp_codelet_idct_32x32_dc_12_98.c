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
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 64; i += 2) {
            int idx = i + j * 64;
            coeffs[idx] = coeff;
            coeffs[idx + 1] = coeff + 1;
        }
    }
}
