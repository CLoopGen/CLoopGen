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
for (i = 0; i < len; i += 2) {
    v0 = 0.F;
    for (j = 0; j < in_ch - 1; j += 2) {
        v0 += samples[j][i] * matrix[0][j] + samples[j+1][i] * matrix[0][j+1];
    }
    if (j == in_ch - 1) {
        v0 += samples[in_ch - 1][i] * matrix[0][in_ch - 1];
    }
    samples[0][i] = v0;
    if (i + 1 < len) {
        v0 = 0.F;
        for (j = 0; j < in_ch; j++) {
            v0 += samples[j][i+1] * matrix[0][j];
        }
        samples[0][i+1] = v0;
    }
}
}
