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
    for (j = 0; j < 32; j++) {
        i = 0;
        for (; i < 32; i++) {
            coeffs[i + j * 32] = coeff;
        }
    }
}
