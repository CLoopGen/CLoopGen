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
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 4; i++) {
            if (!(i == 2 && j == 2)) {
                coeffs[i + j * 4] = coeff;
            }
        }
    }
}
