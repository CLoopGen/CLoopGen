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
    int combined;
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            combined = i + j * 16;
            // Introduce a WAW dependency by writing twice with no intervening read
            local_coeffs[combined] = coeff - 1;
            local_coeffs[combined] = coeff;
        }
    }
}
