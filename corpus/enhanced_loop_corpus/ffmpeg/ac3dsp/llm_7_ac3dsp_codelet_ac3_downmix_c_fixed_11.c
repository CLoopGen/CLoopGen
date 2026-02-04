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
    int64_t acc0 = 0, acc1 = 0;
    for (i = 0; i < len; i++) {
        acc0 = acc1 = 0;
        for (j = 0; j < in_ch; j++) {
            acc0 += (int64_t)samples[j][i] * matrix[0][j];
            acc1 += (int64_t)samples[j][i] * matrix[1][j];
        }
        samples[0][i] = (acc0 + 2048) >> 12;
        samples[1][i] = (acc1 + 2048) >> 12;
    }
    // Introduced WAW-like dependency pattern by reusing accumulators per outer loop iteration
    // Eliminated potential RAW on v0/v1 from outer scope by using local accumulation variables
    // Loop-carried dependencies removed by making accumulators local to each i-iteration
}
