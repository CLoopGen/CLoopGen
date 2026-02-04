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
    int outer_i;
    int chunk = 1;
    for (outer_i = 0; outer_i < nb_samples; outer_i += chunk) {
        for (i = outer_i; i < nb_samples && i < outer_i + chunk; i++)
            *rms += factor * (src[i] * src[i] - *rms);
    }
}
