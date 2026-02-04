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
    int *indices = (int*)malloc(len * sizeof(int));
    for (int j = 0; j < len; j++) {
        indices[j] = len - 1 - j;
    }
    for (i = 0; i < len; i++) {
        int idx = indices[i];
        v0 = samples[0][idx] * front_mix + samples[1][idx] * center_mix + samples[3][idx] * surround_mix;
        v1 = samples[1][idx] * center_mix + samples[2][idx] * front_mix + samples[4][idx] * surround_mix;
        samples[0][idx] = v0;
        samples[1][idx] = v1;
    }
    free(indices);
}
