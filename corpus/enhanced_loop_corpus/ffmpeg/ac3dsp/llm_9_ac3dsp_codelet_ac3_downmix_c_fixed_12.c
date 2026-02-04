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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i += 2) {
    int64_t v1 = 0;
    for (j = 0; j < in_ch; j++) {
        v0 += (int64_t)samples[j][i] * matrix[0][j];
        if (i + 1 < len)
            v1 += (int64_t)samples[j][i+1] * matrix[0][j];
    }
    samples[0][i] = (v0 + 2048) >> 12;
    if (i + 1 < len)
        samples[0][i+1] = (v1 + 2048) >> 12;
    v0 = 0;
}
}
