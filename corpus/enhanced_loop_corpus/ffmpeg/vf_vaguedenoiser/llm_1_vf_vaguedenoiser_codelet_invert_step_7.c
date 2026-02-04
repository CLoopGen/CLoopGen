#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float synthesis_low[7];
extern float *output;
extern float *temp;
extern int i;
extern int findex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (findex + 11 > 9) {
        for (i = 9; i < findex + 11; i++) {
            const float a = temp[i] * synthesis_low[0];
            const float b = temp[i] * synthesis_low[1];
            const float c = temp[i] * synthesis_low[2];
            const float d = temp[i] * synthesis_low[3];
            for (int unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
                output[2 * i - 13] += a;
                output[2 * i - 12] += b;
                output[2 * i - 11] += c;
                output[2 * i - 10] += d;
                output[2 * i - 9] += c;
                output[2 * i - 8] += b;
                output[2 * i - 7] += a;
            }
        }
    }
}
