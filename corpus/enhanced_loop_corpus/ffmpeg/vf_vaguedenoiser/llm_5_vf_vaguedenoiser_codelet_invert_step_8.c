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
for (i = 8; i < findex + 11; i++) {
    const float t_val = temp[i];
    const float a = t_val * synthesis_high[0];
    const float b = t_val * synthesis_high[1];
    const float c = t_val * synthesis_high[2];
    const float d = t_val * synthesis_high[3];
    const float e = t_val * synthesis_high[4];
    const int base_idx = 2 * i;
    if (base_idx >= 13) {
        output[base_idx - 13] += a;
        output[base_idx - 12] += b;
        output[base_idx - 11] += c;
        output[base_idx - 10] += d;
        output[base_idx - 9] += e;
        output[base_idx - 8] += d;
        output[base_idx - 7] += c;
        output[base_idx - 6] += b;
        output[base_idx - 5] += a;
    }
}
}
