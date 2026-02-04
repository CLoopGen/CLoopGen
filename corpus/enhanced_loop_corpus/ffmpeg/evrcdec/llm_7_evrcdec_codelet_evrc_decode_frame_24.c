#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float accumulator = 0.0f;
    for (i = 0; i < 160; i++) {
        accumulator += samples[i];
        samples[i] = accumulator / 32768;
        accumulator = samples[i];
    }
}
