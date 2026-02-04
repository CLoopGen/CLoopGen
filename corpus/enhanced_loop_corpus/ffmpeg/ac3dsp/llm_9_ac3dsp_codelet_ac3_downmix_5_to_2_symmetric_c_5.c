#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern int len;
extern int i;
extern float v0;
extern float v1;
extern float front_mix;
extern float center_mix;
extern float surround_mix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    float temp0 = samples[0][i] * front_mix;
    float temp1 = samples[1][i] * center_mix;
    float temp3 = samples[3][i] * surround_mix;
    float temp2 = samples[2][i] * front_mix;
    float temp4 = samples[4][i] * surround_mix;

    v0 = temp0 + temp1 + temp3;
    v1 = temp1 + temp2 + temp4;

    samples[0][i] = v0;
    samples[1][i] = v1;
}
}
