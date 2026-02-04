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
        for (i = 0; i < 4; i += 2) {
            int16_t temp1 = coeff + i;
            int16_t temp2 = coeff - i;
            coeffs[i + j * 4] = temp1;
            if (i + 1 < 4) {
                coeffs[i + 1 + j * 4] = temp2;
            }
        }
    }
}
