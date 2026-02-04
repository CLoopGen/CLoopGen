#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double c4[4][4];
extern double block2[64];
extern double block3[64];
extern double sum;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    for (j = 0; j < 4; j++) {
        double sum1 = 0, sum2 = 0;
        double sum3 = 0, sum4 = 0;
        for (k = 0; k < 4; k++) {
            double coeff = c4[k][j];
            sum1 += coeff * block2[8 * (2 * k) + i];
            sum2 += coeff * block2[8 * (2 * k + 1) + i];
            if (i + 1 < 8) {
                sum3 += coeff * block2[8 * (2 * k) + i + 1];
                sum4 += coeff * block2[8 * (2 * k + 1) + i + 1];
            }
        }
        block3[8 * (2 * j) + i] = sum1;
        block3[8 * (2 * j + 1) + i] = sum2;
        if (i + 1 < 8) {
            block3[8 * (2 * j) + i + 1] = sum3;
            block3[8 * (2 * j + 1) + i + 1] = sum4;
        }
    }
}
}
