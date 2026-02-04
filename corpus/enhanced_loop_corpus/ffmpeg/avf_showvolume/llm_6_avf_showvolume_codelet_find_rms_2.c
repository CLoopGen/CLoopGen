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
    float temp_rms = *rms;
    for (i = 0; i < nb_samples; i++) {
        temp_rms = temp_rms + factor * (src[i] * src[i] - temp_rms);
    }
    *rms = temp_rms;
}
