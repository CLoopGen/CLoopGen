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
        double acc0 = 0, acc1 = 0, acc2 = 0, acc3 = 0;
        double acc4 = 0, acc5 = 0, acc6 = 0, acc7 = 0;
        for (k = 0; k < 8; ++k) {
            acc0 += coefficients[i + k] * block[k * 8 + 0];
            acc1 += coefficients[i + k] * block[k * 8 + 1];
            acc2 += coefficients[i + k] * block[k * 8 + 2];
            acc3 += coefficients[i + k] * block[k * 8 + 3];
            acc4 += coefficients[i + k] * block[k * 8 + 4];
            acc5 += coefficients[i + k] * block[k * 8 + 5];
            acc6 += coefficients[i + k] * block[k * 8 + 6];
            acc7 += coefficients[i + k] * block[k * 8 + 7];
        }
        out[i + 0] = acc0 * 8;
        out[i + 1] = acc1 * 8;
        out[i + 2] = acc2 * 8;
        out[i + 3] = acc3 * 8;
        out[i + 4] = acc4 * 8;
        out[i + 5] = acc5 * 8;
        out[i + 6] = acc6 * 8;
        out[i + 7] = acc7 * 8;
    }
}
