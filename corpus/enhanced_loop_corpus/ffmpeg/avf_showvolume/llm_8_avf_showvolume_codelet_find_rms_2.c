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
    int j;
    for (i = 0; i < nb_samples; i += 2) {
        float sum_sq = 0.0f;
        int k = i + 1;
        sum_sq += src[i] * src[i];
        if (k < nb_samples) sum_sq += src[k] * src[k];
        *rms += factor * (sum_sq - *rms);
    }
}
