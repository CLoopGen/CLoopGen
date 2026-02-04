#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 160; i++) {
        if (i >= 10 && i < 150) {
            samples[i] /= 32768;
        } else {
            samples[i] *= 1.0f;
        }
    }
}
