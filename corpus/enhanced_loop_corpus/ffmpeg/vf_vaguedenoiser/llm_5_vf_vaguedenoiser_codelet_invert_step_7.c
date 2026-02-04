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
    for (i = 9; i < findex + 11; i++) {
        const float t_val = temp[i];
        const float a = t_val * synthesis_low[0];
        const float b = t_val * synthesis_low[1];
        const float c = t_val * synthesis_low[2];
        const float d = t_val * synthesis_low[3];
        const int base_idx = 2 * i;
        if (base_idx >= 14) {
            output[base_idx - 13] += a;
            output[base_idx - 12] += b;
            output[base_idx - 11] += c;
            output[base_idx - 10] += d;
            output[base_idx - 9] += c;
            output[base_idx - 8] += b;
            output[base_idx - 7] += a;
        }
    }
}
