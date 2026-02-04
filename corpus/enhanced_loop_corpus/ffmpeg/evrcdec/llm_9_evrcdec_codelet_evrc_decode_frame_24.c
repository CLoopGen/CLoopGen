#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *samples;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float scale1 = 1.0f / 32768;
    float scale2 = scale1 * 2;
    for (i = 0; i < 80; i++) {
        samples[2*i]     *= scale1;
        samples[2*i + 1] *= scale1;
        samples[2*i]     += samples[2*i]; // Extra arithmetic operation: doubling value
        samples[2*i]     *= scale2;        // Additional intensity via redundant scaling
    }
}
