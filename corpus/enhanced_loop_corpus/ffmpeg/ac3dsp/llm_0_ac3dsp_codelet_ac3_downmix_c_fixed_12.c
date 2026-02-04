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
    v0 = 0;
    for (i = 0; i < len; i++) {
        v0 += (int64_t)samples[0][i] * matrix[0][0];
        samples[0][i] = (v0 + 2048) >> 12;
    }
}
