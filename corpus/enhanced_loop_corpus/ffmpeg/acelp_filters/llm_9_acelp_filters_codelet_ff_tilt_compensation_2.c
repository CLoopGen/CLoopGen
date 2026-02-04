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
    float tilt_sq = tilt * tilt;
    for (i = size - 1; i > 2; i--) {
        samples[i] -= tilt * samples[i - 1] + tilt_sq * samples[i - 2];
    }
}
