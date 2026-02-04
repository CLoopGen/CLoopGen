#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 160; i++) {
        if (samples[i] != 0) {
            samples[i] /= 32768;
        }
    }
}
