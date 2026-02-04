#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float analysis_low[9];
extern float *input;
extern float *output;
extern  int low_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 10; i < 10 + low_size; i++) {
        if (i >= 15) {
            const float a = input[2 * i - 14] * analysis_low[0];
            const float b = input[2 * i - 13] * analysis_low[1];
            const float c = input[2 * i - 12] * analysis_low[2];
            const float d = input[2 * i - 11] * analysis_low[3];
            const float e = input[2 * i - 10] * analysis_low[4];
            const float f = input[2 * i - 9] * analysis_low[3];
            const float g = input[2 * i - 8] * analysis_low[2];
            const float h = input[2 * i - 7] * analysis_low[1];
            const float k = input[2 * i - 6] * analysis_low[0];
            output[i] = a + b + c + d + e + f + g + h + k;
        }
    }
}
