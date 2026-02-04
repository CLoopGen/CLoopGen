#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern int len;
extern int i;
extern float front_mix;
extern float center_mix;
extern float surround_mix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < len; i++) {
        temp = samples[0][i] * front_mix + samples[1][i] * center_mix;
        temp += samples[2][i] * front_mix;
        temp += samples[3][i] * surround_mix;
        temp += samples[4][i] * surround_mix;
        samples[0][i] = temp;
    }
}
