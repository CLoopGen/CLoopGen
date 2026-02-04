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
extern int v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i += 2) {
    v0 = v1 = 0;
    int temp0 = 0, temp1 = 0;
    for (j = 0; j < in_ch; j++) {
        temp0 += samples[j][i] * matrix[0][j];
        if (i + 1 < len) {
            temp1 += samples[j][i+1] * matrix[1][j];
        }
    }
    samples[0][i] = (temp0 + 2048) >> 12;
    if (i + 1 < len) {
        samples[1][i+1] = (temp1 + 2048) >> 12;
    }
}
}
