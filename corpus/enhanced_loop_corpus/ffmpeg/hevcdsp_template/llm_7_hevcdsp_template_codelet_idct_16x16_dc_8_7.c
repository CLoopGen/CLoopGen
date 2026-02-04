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
        int16_t prev = 0;
        for (i = 0; i < 16; i++) {
            if (i == 0) {
                coeffs[i + j * 16] = coeff;
                prev = coeff;
            } else {
                coeffs[i + j * 16] = prev + coeff; // Introduce RAW loop-carried dependency: each write depends on previous iteration
                prev = coeffs[i + j * 16];
            }
        }
    }
}
