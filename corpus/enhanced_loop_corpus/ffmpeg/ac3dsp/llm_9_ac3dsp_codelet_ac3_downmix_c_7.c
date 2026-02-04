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
extern float v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        v0 = v1 = 0.F;
        for (j = 0; j < in_ch && j < 4; j++) {
            float temp = samples[j][i];
            v0 += temp * matrix[0][j];
            v1 += temp * matrix[1][j];
        }
        samples[0][i] = v0 * 0.5F;
        samples[1][i] = v1 * 0.5F;
    }
}
