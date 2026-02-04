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
    for (j = 0; j < 2; j += 1) {
        for (i = 0; i < 2; i += 1) {
            int16_t temp = coeff + (i ^ j);
            coeffs[i * 2 + j] = temp;
            coeffs[i * 2 + j + 2] = temp;
            coeffs[i * 2 + j + 8] = temp;
            coeffs[i * 2 + j + 10] = temp;
        }
    }
}
