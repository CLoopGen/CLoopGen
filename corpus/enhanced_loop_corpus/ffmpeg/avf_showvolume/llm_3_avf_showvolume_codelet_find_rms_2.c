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
    // Variant 2: Reverse consecutive access from end to start
    for (i = nb_samples - 1; i >= 0; i--)
        *rms += factor * (src[i] * src[i] - *rms);
}
