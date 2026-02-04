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
for (i = 0; i < len; i += 2) {
    int32_t v0_0 = 0, v0_1 = 0;
    for (j = 0; j < in_ch; j++) {
        v0_0 += samples[j][i] * matrix[0][j];
        if (i + 1 < len) {
            v0_1 += samples[j][i+1] * matrix[0][j];
        }
    }
    samples[0][i] = (v0_0 + 2048) >> 12;
    if (i + 1 < len) {
        samples[0][i+1] = (v0_1 + 2048) >> 12;
    }
}
}
