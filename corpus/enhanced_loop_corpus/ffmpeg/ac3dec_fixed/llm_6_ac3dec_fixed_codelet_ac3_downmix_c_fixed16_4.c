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
    int temp[len];
    for (i = 0; i < len; i++) {
        v0 = 0;
        for (j = 0; j < in_ch; j++)
            v0 += samples[j][i] * matrix[0][j];
        temp[i] = (v0 + 2048) >> 12;
    }
    for (i = 0; i < len; i++) {
        samples[0][i] = temp[i];
    }
}
