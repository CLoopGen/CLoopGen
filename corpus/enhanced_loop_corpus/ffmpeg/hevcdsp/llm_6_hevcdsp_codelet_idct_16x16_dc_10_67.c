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
    int16_t temp[256];
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            temp[i + j * 16] = coeff;
        }
    }
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            coeffs[i + j * 16] = temp[i + j * 16];
        }
    }
}
