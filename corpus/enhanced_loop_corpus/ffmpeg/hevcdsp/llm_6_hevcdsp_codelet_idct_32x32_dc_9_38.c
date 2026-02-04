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
    int16_t *local_coeffs = coeffs;
    int idx;
    for (j = 0; j < 32; j++) {
        idx = j * 32;
        for (i = 0; i < 32; i++) {
            local_coeffs[idx + i] = coeff;
        }
    }
}
