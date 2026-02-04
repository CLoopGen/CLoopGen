#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t **samples;
extern int16_t **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern int64_t v0;
extern int64_t v1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        v0 = v1 = 0;
        for (j = 0; j < in_ch; j++) {
            if (matrix[0][j] != 0 || matrix[1][j] != 0) {
                v0 += (int64_t)samples[j][i] * matrix[0][j];
                v1 += (int64_t)samples[j][i] * matrix[1][j];
            }
        }
        if ((v0 | v1) != 0) {
            samples[0][i] = (v0 + 2048) >> 12;
            samples[1][i] = (v1 + 2048) >> 12;
        } else {
            samples[0][i] = 0;
            samples[1][i] = 0;
        }
    }
}
