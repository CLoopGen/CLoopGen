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
    float acc[9] = {0};
    acc[0] = t_val * synthesis_high[0];
    acc[1] = t_val * synthesis_high[1];
    acc[2] = t_val * synthesis_high[2];
    acc[3] = t_val * synthesis_high[3];
    acc[4] = t_val * synthesis_high[4];
    acc[5] = acc[3];
    acc[6] = acc[2];
    acc[7] = acc[1];
    acc[8] = acc[0];
    const int base_idx = 2 * i - 13;
    for (int j = 0; j < 9; j++) {
        output[base_idx + j] += acc[j];
    }
}
}
