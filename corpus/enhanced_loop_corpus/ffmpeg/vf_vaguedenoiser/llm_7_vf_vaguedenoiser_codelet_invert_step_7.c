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
        output[2 * i - 13] = a;
        output[2 * i - 12] = b;
        output[2 * i - 11] = c;
        output[2 * i - 10] = d;
        output[2 * i - 9] = c;
        output[2 * i - 8] = b;
        output[2 * i - 7] = a;
    }
}
