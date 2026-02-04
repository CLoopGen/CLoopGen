#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int nb_samples;
extern float *rms;
extern float factor;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nb_samples; i++) {
    float sq = src[i] * src[i];
    if (sq >= *rms) {
        *rms += factor * (sq - *rms);
    } else {
        continue;
    }
}
}
