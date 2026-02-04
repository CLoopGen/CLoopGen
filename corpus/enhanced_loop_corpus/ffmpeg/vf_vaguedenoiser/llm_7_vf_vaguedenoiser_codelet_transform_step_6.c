#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float analysis_high[7];
extern float *input;
extern float *output;
extern  int low_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 10; i < 10 + low_size; i += 2) {
        const int idx1 = 2 * i - 12;
        const int idx2 = 2 * i - 11;
        const int idx3 = 2 * i - 10;
        const int idx4 = 2 * i - 9;
        const int idx5 = 2 * i - 8;
        const int idx6 = 2 * i - 7;
        const int idx7 = 2 * i - 6;

        const float a = input[idx1] * analysis_high[0];
        const float b = input[idx2] * analysis_high[1];
        const float c = input[idx3] * analysis_high[2];
        const float d = input[idx4] * analysis_high[3];
        const float e = input[idx5] * analysis_high[2];
        const float f = input[idx6] * analysis_high[1];
        const float g = input[idx7] * analysis_high[0];

        const float sum1 = a + b + c + d + e + f + g;
        output[i + low_size] = sum1;

        if (i + 1 < 10 + low_size) {
            const float a2 = input[idx1 + 2] * analysis_high[0];
            const float b2 = input[idx2 + 2] * analysis_high[1];
            const float c2 = input[idx3 + 2] * analysis_high[2];
            const float d2 = input[idx4 + 2] * analysis_high[3];
            const float e2 = input[idx5 + 2] * analysis_high[2];
            const float f2 = input[idx6 + 2] * analysis_high[1];
            const float g2 = input[idx7 + 2] * analysis_high[0];
            const float sum2 = a2 + b2 + c2 + d2 + e2 + f2 + g2;
            output[i + 1 + low_size] = sum2;
        }
    }
}
