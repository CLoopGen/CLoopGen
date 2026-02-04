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
    int outer_i;
    int block_size = 16;
    for (outer_i = 0; outer_i < len; outer_i += block_size) {
        for (i = outer_i; i < len && i < outer_i + block_size; i++) {
            samples[0][i] = samples[0][i] * front_mix + samples[1][i] * center_mix + samples[2][i] * front_mix + samples[3][i] * surround_mix + samples[4][i] * surround_mix;
        }
    }
}
