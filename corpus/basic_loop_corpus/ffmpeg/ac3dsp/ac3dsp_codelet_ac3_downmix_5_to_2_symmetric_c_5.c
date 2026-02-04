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
    v0 = samples[0][i] * front_mix + samples[1][i] * center_mix + samples[3][i] * surround_mix;
    v1 = samples[1][i] * center_mix + samples[2][i] * front_mix + samples[4][i] * surround_mix;
    samples[0][i] = v0;
    samples[1][i] = v1;
}

}
