#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 1.0f / 32768;
    for (i = 0; i < 160; i++) {
        samples[i] *= temp;
    }
}
