#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 320; i += 2) {
        samples[i] /= 32768;
        if (i + 1 < 160) {
            samples[i + 1] /= 32768;
        }
    }
}
