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
for (i = 0; i < len; i += 2) {
    v0 = v1 = 0;
    int64_t v2 = 0, v3 = 0;
    for (j = 0; j < in_ch; j++) {
        v0 += (int64_t)samples[j][i] * matrix[0][j];
        v1 += (int64_t)samples[j][i] * matrix[1][j];
        if (i + 1 < len) {
            v2 += (int64_t)samples[j][i+1] * matrix[0][j];
            v3 += (int64_t)samples[j][i+1] * matrix[1][j];
        }
    }
    samples[0][i] = (v0 + 2048) >> 12;
    samples[1][i] = (v1 + 2048) >> 12;
    if (i + 1 < len) {
        samples[0][i+1] = (v2 + 2048) >> 12;
        samples[1][i+1] = (v3 + 2048) >> 12;
    }
}
}
