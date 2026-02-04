#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float synthesis_high[9];
extern float *output;
extern float *temp;
extern int i;
extern int findex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (findex + 11 > 8) {
        for (i = 8; i < findex + 11; i += 2) {
            for (int unroll_factor = 0; unroll_factor < 2; unroll_factor++) {
                if (i + unroll_factor >= findex + 11) break;
                const int idx = i + unroll_factor;
                const float t_val = temp[idx];
                const float a = t_val * synthesis_high[0];
                const float b = t_val * synthesis_high[1];
                const float c = t_val * synthesis_high[2];
                const float d = t_val * synthesis_high[3];
                const float e = t_val * synthesis_high[4];
                output[2 * idx - 13] += a;
                output[2 * idx - 12] += b;
                output[2 * idx - 11] += c;
                output[2 * idx - 10] += d;
                output[2 * idx - 9] += e;
                output[2 * idx - 8] += d;
                output[2 * idx - 7] += c;
                output[2 * idx - 6] += b;
                output[2 * idx - 5] += a;
            }
        }
    }
}
