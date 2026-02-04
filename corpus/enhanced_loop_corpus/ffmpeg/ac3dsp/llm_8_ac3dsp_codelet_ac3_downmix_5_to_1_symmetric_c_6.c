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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            samples[0][i]   = samples[0][i] * front_mix + samples[1][i] * center_mix;
            samples[0][i+1] = samples[0][i+1] * front_mix + samples[2][i+1] * front_mix + samples[3][i+1] * surround_mix;
        } else {
            samples[0][i] = samples[0][i] * front_mix + samples[1][i] * center_mix;
        }
    }
}
