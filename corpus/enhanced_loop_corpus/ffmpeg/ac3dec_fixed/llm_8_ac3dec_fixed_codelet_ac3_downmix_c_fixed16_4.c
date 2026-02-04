#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t **samples;
extern int16_t **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern int v0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    v0 = 0;
    for (j = 0; j < in_ch; j += 2) {
        if (j + 1 < in_ch) {
            v0 += (samples[j][i] * matrix[0][j]) + (samples[j+1][i] * matrix[0][j+1]);
        } else {
            v0 += samples[j][i] * matrix[0][j];
        }
    }
    samples[0][i] = (v0 + 2048) >> 12;
}
}
