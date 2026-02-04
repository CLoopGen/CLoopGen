#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern float **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern float v0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    v0 = 0.F;
    float sum1 = 0.F, sum2 = 0.F, sum3 = 0.F, sum4 = 0.F;
    int remainder = in_ch % 4;
    int limit = in_ch - remainder;

    for (j = 0; j < limit; j += 4) {
        sum1 += samples[j][i] * matrix[0][j];
        sum2 += samples[j+1][i] * matrix[0][j+1];
        sum3 += samples[j+2][i] * matrix[0][j+2];
        sum4 += samples[j+3][i] * matrix[0][j+3];
    }

    v0 = sum1 + sum2 + sum3 + sum4;

    for (j = limit; j < in_ch; j++) {
        v0 += samples[j][i] * matrix[0][j];
    }

    samples[0][i] = v0;
}
}
