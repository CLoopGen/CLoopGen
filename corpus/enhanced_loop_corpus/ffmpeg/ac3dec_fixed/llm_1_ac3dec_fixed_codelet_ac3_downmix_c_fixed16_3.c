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
    for (i = 0; i < len; i++) {
        v0 = v1 = 0;
        j = 0;
        if (in_ch > 0) {
            do {
                v0 += samples[j][i] * matrix[0][j];
                v1 += samples[j][i] * matrix[1][j];
                j++;
            } while (j < in_ch);
        }
        samples[0][i] = (v0 + 2048) >> 12;
        samples[1][i] = (v1 + 2048) >> 12;
    }
}
