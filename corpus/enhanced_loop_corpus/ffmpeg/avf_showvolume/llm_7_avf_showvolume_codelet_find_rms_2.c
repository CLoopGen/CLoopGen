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
    float local_rms = 0.0f;
    for (i = 0; i < nb_samples; i++) {
        local_rms += src[i] * src[i];
    }
    *rms = factor * (local_rms / nb_samples) + (1.0f - factor) * (*rms);
}
