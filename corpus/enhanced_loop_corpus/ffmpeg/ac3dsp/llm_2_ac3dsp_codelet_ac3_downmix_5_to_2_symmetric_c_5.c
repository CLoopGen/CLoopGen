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
    int stride = 2;
    for (i = 0; i < len; i += stride) {
        if (i + 1 < len) {
            v0 = samples[0][i] * front_mix + samples[1][i] * center_mix + samples[3][i] * surround_mix;
            v1 = samples[1][i] * center_mix + samples[2][i] * front_mix + samples[4][i] * surround_mix;
            samples[0][i] = v0;
            samples[1][i] = v1;

            v0 = samples[0][i+1] * front_mix + samples[1][i+1] * center_mix + samples[3][i+1] * surround_mix;
            v1 = samples[1][i+1] * center_mix + samples[2][i+1] * front_mix + samples[4][i+1] * surround_mix;
            samples[0][i+1] = v0;
            samples[1][i+1] = v1;
        } else {
            v0 = samples[0][i] * front_mix + samples[1][i] * center_mix + samples[3][i] * surround_mix;
            v1 = samples[1][i] * center_mix + samples[2][i] * front_mix + samples[4][i] * surround_mix;
            samples[0][i] = v0;
            samples[1][i] = v1;
        }
    }
}
