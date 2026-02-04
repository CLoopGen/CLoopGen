#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float tilt;
extern float *samples;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_accum = 0.0f;
    float tilt_val = tilt;
    for (i = size - 1; i >= 0; i--) {
        local_accum += samples[i];
        samples[i] = samples[i] - tilt_val * local_accum;
    }
}
