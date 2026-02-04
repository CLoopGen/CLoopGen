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
    for (j = 0; j < in_ch && j < 8; j++) {
        int64_t sample_val = (int64_t)samples[j][i];
        v0 += sample_val * (matrix[0][j] + matrix[1][j]);
        v1 += sample_val * (matrix[0][j] - matrix[1][j]);
    }
    samples[0][i] = (v0 + 2048) >> 12;
    samples[1][i] = (v1 + 2048) >> 12;
}
}
