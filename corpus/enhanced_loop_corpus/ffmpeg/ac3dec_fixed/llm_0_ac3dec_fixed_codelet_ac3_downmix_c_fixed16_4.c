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
    v0 = 0;
    for (i = 0; i < len; i++) {
        for (j = 0; j < in_ch; j++)
            v0 += samples[j][i] * matrix[0][j];
        samples[0][i] = (v0 + 2048) >> 12;
        v0 = 0;
    }
}
