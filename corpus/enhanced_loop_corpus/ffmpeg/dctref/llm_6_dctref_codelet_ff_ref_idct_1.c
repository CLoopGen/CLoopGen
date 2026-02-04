#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coefficients[64];
extern short *block;
extern unsigned int i;
extern unsigned int j;
extern unsigned int k;
extern double out[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_out[64] = {0};
    for (i = 0; i < 64; i += 8) {
        for (k = 0; k < 8; ++k) {
            double coeff_slice[8];
            for (j = 0; j < 8; ++j) {
                coeff_slice[j] = coefficients[k * 8 + j];
            }
            for (j = 0; j < 8; ++j) {
                temp_out[i + j] += block[i + k] * coeff_slice[j];
            }
        }
    }
    for (i = 0; i < 64; ++i) {
        out[i] = temp_out[i];
    }
}
