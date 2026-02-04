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
    // Variant 1: Strided Memory Access (access every 2nd element in two passes)
    int stride = 2;
    for (i = 0; i < len; i += stride) {
        if (i < len) {
            samples[0][i] = samples[0][i] * front_mix + samples[1][i] * center_mix + samples[2][i] * front_mix + samples[3][i] * surround_mix + samples[4][i] * surround_mix;
        }
        int next = i + 1;
        if (next < len) {
            samples[0][next] = samples[0][next] * front_mix + samples[1][next] * center_mix + samples[2][next] * front_mix + samples[3][next] * surround_mix + samples[4][next] * surround_mix;
        }
    }
}
