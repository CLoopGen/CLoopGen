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
    if (low_size > 0) {
        for (int outer = 0; outer < (low_size + 7) / 8; outer++) {
            for (int inner = 0; inner < 8; inner++) {
                int idx = 10 + outer * 8 + inner;
                if (idx >= 10 + low_size) break;
                const float a = input[2 * idx - 14] * analysis_low[0];
                const float b = input[2 * idx - 13] * analysis_low[1];
                const float c = input[2 * idx - 12] * analysis_low[2];
                const float d = input[2 * idx - 11] * analysis_low[3];
                const float e = input[2 * idx - 10] * analysis_low[4];
                const float f = input[2 * idx - 9]  * analysis_low[3];
                const float g = input[2 * idx - 8]  * analysis_low[2];
                const float h = input[2 * idx - 7]  * analysis_low[1];
                const float k = input[2 * idx - 6]  * analysis_low[0];
                output[idx] = a + b + c + d + e + f + g + h + k;
            }
        }
    }
}
