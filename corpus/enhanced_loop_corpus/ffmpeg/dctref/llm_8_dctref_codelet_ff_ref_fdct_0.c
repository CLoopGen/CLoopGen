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
for (i = 0; i < 64; i += 16) {
    for (j = 0; j < 8; ++j) {
        double tmp0 = 0, tmp1 = 0;
        for (k = 0; k < 8; ++k) {
            tmp0 += coefficients[i + k] * block[k * 8 + j];
            tmp1 += coefficients[i + 8 + k] * block[k * 8 + j];
        }
        out[i + j] = tmp0 * 8;
        out[i + 8 + j] = tmp1 * 8;
    }
}
}
