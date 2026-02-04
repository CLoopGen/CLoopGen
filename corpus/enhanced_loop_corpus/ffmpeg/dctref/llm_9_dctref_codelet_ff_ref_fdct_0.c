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
for (i = 0; i < 64; i += 8) {
    for (j = 0; j < 8; ++j) {
        double tmp = 0;
        for (k = 0; k < 4; ++k) {
            tmp += coefficients[i + 2*k] * block[(2*k) * 8 + j] +
                   coefficients[i + 2*k + 1] * block[(2*k + 1) * 8 + j];
        }
        out[i + j] = tmp * 8;
    }
}
}
