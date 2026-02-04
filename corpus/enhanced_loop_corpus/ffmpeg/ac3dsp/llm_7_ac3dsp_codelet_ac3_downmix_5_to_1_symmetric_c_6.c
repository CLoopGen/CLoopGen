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
    if (len > 0) {
        samples[0][0] = samples[0][0] * front_mix + samples[1][0] * center_mix + samples[2][0] * front_mix + samples[3][0] * surround_mix + samples[4][0] * surround_mix;
        for (i = 1; i < len; i++) {
            samples[0][i] = samples[0][i-1] * front_mix + samples[1][i] * center_mix + samples[2][i] * front_mix + samples[3][i] * surround_mix + samples[4][i] * surround_mix;
        }
    }
}
