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
            if (i == 0 && j == 0) {
                coeffs[i + j * 4] = coeff;
            } else {
                coeffs[i + j * 4] = coeffs[(i - 1 + (j * 4 + (i == 0 ? -4 : 0))) % 16] + (coeff - coeffs[(i - 1 + (j * 4 + (i == 0 ? -4 : 0))) % 16]);
            }
        }
    }
}
