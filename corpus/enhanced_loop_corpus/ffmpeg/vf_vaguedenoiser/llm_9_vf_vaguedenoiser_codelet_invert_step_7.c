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
    const float e = t_val * synthesis_low[4];
    const float f = t_val * synthesis_low[5];
    const float g = t_val * synthesis_low[6];
    const int base_idx = 2 * i - 13;
    output[base_idx]     += a;
    output[base_idx + 1] += b;
    output[base_idx + 2] += c;
    output[base_idx + 3] += d;
    output[base_idx + 4] += e;
    output[base_idx + 5] += f;
    output[base_idx + 6] += g;
    output[base_idx + 7] += f;
    output[base_idx + 8] += e;
    output[base_idx + 9] += d;
    output[base_idx + 10] += c;
    output[base_idx + 11] += b;
    output[base_idx + 12] += a;
}
}
