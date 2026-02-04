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
        if (j % 2 == 0) {
            for (i = 0; i < 16; i++) {
                coeffs[i + j * 16] = coeff;
            }
        } else {
            for (i = 0; i < 16; i += 2) {
                coeffs[i + j * 16] = coeff;
            }
        }
    }
}
